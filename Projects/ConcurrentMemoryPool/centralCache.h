#pragma once

#include"common.h"
#include"pageCache.h"

//singleton mode
class CentralCache
{
public:
    static CentralCache* getInstance()
    {
        return &_sInst;
    }
    Span* GetOneSpan(SpanList& list, size_t size)
    {
        //check if there is an available span
        Span *it = list.Begin();
        while( it != list.End())
        {
            if(it->_freeList != nullptr)
                return it;
            else 
                it = it->_next;
        }
        //unlock (in case other threads free objects)
        list._mtx.unlock();

        //No available span , fetch from Page cache.
        PageCache::getInstance()->_pageMtx.lock();
        Span *span = PageCache::getInstance()->NewSpan(sizeClass::NumMovePage(size));
        //span is used.
        span->_ifBeingUsed = true;
        PageCache::getInstance()->_pageMtx.unlock();

        // slice the acquired span, no need for locking, because no other threads can access this span
        // 1. calculate the begining of the memory and byte size of memory
        char *begin = (char *)(span->_pageid << PAGE_SHIFT);
        size_t bytes = span->_n << PAGE_SHIFT;
        char *end = begin + bytes;

        // 2. cutting the span, and link
        span->_freeList = begin;
        begin += size;
        void *tail = span->_freeList;
        while(begin < end)
        {
            NextObj(tail) = begin;
            tail = NextObj(tail);
            begin += size;
        }
        list._mtx.lock();
        list.PushFront(span);
        list._mtx.unlock();
        return span;
    }
    //fetch some blocks from central cache
    size_t FetchRangeObj(void*& begin, void*& end, size_t n, size_t size)
    {
        size_t index = sizeClass::index(size);
        _spanLists[index]._mtx.lock();
        Span *span = GetOneSpan(_spanLists[index], size);
        assert(span);
        assert(span->_freeList);
        begin = span->_freeList;
        end = begin;
        size_t i = 0, acutalNum = 1;
        while( i < n - 1 && NextObj(end) != nullptr)
        {
            end = NextObj(end);
            ++ i;
            ++acutalNum;
        }
        span->_freeList = NextObj(end);
        NextObj(end) = nullptr;
        _spanLists[index]._mtx.unlock();
        return acutalNum;
    }
    void ReleaseListToSpans(void* begin ,size_t size)
    {
        size_t index = sizeClass::index(size);
        _spanLists[index]._mtx.lock();
        while(begin)
        {
            void *next = NextObj(begin);
            Span *span = PageCache::getInstance()->MapObjToSpan(begin);
            NextObj(begin) = span->_freeList;
            span->_freeList = begin;
            --span->_useCount;
            // all small blocks are returned, the span can be returned to pagecache
            if(span->_useCount == 0)
            {
                _spanLists[index].Erase(span);
                span->_freeList = nullptr;
                span->_next = nullptr;
                span->_prev = nullptr;
                span->_ifBeingUsed = false;
                _spanLists[index]._mtx.unlock();
                PageCache::getInstance()->_pageMtx.lock();
                PageCache::getInstance()->ReleaseSpanToPageCache(span);
                PageCache::getInstance()->_pageMtx.unlock();
                _spanLists[index]._mtx.unlock();
            }
            begin = next;
        }

        _spanLists[index]._mtx.unlock();
    }

private:
    SpanList _spanLists[NUM_FREELISTS];

private:
    CentralCache()
    {}
    CentralCache(const CentralCache &) = delete;

    static CentralCache _sInst;

};