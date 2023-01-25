#pragma once
#include "common.h"
#include "objectMemoryPool.h"
#include "pageMap.h"

class PageCache
{
public:
    static PageCache *getInstance()
    {
        return &_sInst;
    }
    Span *MapObjToSpan(void *obj)
    {
        // std::unique_lock lock(_pageMtx); 
        // // calculate pageid
        // PAGE_ID id = (PAGE_ID)obj >> PAGE_SHIFT;
        // auto ret = _idSpanMap.find(id);
        // if (ret != _idSpanMap.end())
        // {
        //     return ret->second;
        // }
        // else
        // {
        //     assert(false);
        //     return nullptr;
        // }

        //no need for locking
        PAGE_ID id = (PAGE_ID)obj >> PAGE_SHIFT;
        auto ret = (Span *)_idSpanMap.get(id);
        assert(ret != nullptr);
        return ret;
    }
    void ReleaseSpanToPageCache(Span *span)
    {
        // > 128 page , return to the heap 
        if(span->_n > NUM_PAGES - 1)
        {
            void *ptr = (void *)(span->_pageid << PAGE_SHIFT);
            SystemFree(ptr);
            delete span;

            return;
        }
        // attempt merging of adjacent span pages
        // mitigating memory fragmentation
        //  need a mapping from pageid to span
        while (1)
        {
            PAGE_ID prevId = span->_pageid - 1;
            // auto ret = _idSpanMap.find(prevId);
            auto ret = (Span *)_idSpanMap.get(prevId);
            // no more pages ahead
            // if (ret == _idSpanMap.end())
            //     break;
            if(ret == nullptr)
                break;
            // previous page is being used
            // Span *prevSpan = ret->second;
            Span *prevSpan = ret;
            if (prevSpan->_ifBeingUsed == true)
                break;
            //more than NUM_PAGES, cannot control
            if(prevSpan->_n + span->_n >= NUM_PAGES)
                break;
            span->_pageid = prevSpan->_pageid;
            span->_n += prevSpan->_n;
            _spanLists[prevSpan->_n].Erase(prevSpan);
            delete prevSpan;
        }
        while(1)
        {
            PAGE_ID nextId = span->_pageid + span->_n;
            // auto ret = _idSpanMap.find(nextId);
            auto ret = _idSpanMap.get(nextId);
            // if(ret == _idSpanMap.end())
            //     break;
            if(ret == nullptr)
                break;
            // Span *nextSpan = ret->second;
            Span *nextSpan = ret;
            if(nextSpan->_ifBeingUsed == true)
                break;
            if(nextSpan->_n + span->_n >= NUM_PAGES)
                break;
            span->_n += nextSpan->_n;
            _spanLists[nextSpan->_n].Erase(nextSpan);
            delete nextSpan;
        }
        _spanLists[span->_n].PushFront(span);
        span->_ifBeingUsed = false;
        // _idSpanMap[span->_pageid] = span;
        _idSpanMap.set(span->_pageid, span);
        // _idSpanMap[span->_pageid + span->_n - 1] = span;
        _idSpanMap.set(span->_pageid + span->_n, span);
    }
    // get a span (K pages)
    Span * NewSpan(size_t npage)
    {
        assert(npage > 0);
        // > 128 page , apply memory from the heap
        if (npage > NUM_PAGES - 1)
        {
            void *ptr = SystemAlloc(npage);
            // Span *span = new Span;
            Span *span = _spanPool.New();

            span->_pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
            span->_n = npage;
            
            // _idSpanMap[span->_pageid] = span;
            _idSpanMap.set(span->_pageid, span);

            return span;
        }
        // check if there is a span in _spanlists[npage]
        if (!_spanLists[npage].Empty())
        {
            Span* nPageSpan = _spanLists[npage].PopFront();
            for (PAGE_ID i = 0; i < nPageSpan->_n; ++i)
            {
                // _idSpanMap[nPageSpan->_pageid + i] = nPageSpan;
                _idSpanMap.set(nPageSpan->_pageid + i, nPageSpan);
            }
            return nPageSpan;
        }
        // if no span for npage, search for bigger one，cutting
        for (size_t i = npage + 1; i < NUM_PAGES; ++i)
        {
            if (!_spanLists[i].Empty())
            {
                Span *curSpan = _spanLists[i].PopFront();
                // Span *nPageSpan = new Span;
                Span *nPageSpan = _spanPool.New();
                // cutting
                nPageSpan->_pageid = curSpan->_pageid;
                nPageSpan->_n = npage;

                curSpan->_pageid += npage;
                curSpan->_n -= npage;

                _spanLists[curSpan->_n].PushFront(curSpan);
                // we need Mapping of first & last page number and curSpan
                // to recycle memory
                // _idSpanMap[curSpan->_pageid] = curSpan;
                _idSpanMap.set(curSpan->_pageid, curSpan);
                // _idSpanMap[curSpan->_pageid + curSpan->_n - 1] = curSpan;
                _idSpanMap.set(curSpan->_pageid + curSpan->_n - 1, curSpan);

                //  Create a mapping to facilitate finding the corresponding span when reclaiming small chunks of memory
                for (PAGE_ID i = 0; i < nPageSpan->_n; ++i)
                {
                    // _idSpanMap[nPageSpan->_pageid + i] = nPageSpan;
                    _idSpanMap.set(nPageSpan->_pageid + i, nPageSpan);
                }
                return nPageSpan;
            }
        }
        // no extra span,  apply for memory
        //Span *bigSpan = new Span;
        Span *bigSpan = _spanPool.New();
        void *ptr = SystemAlloc(NUM_PAGES - 1);
        bigSpan->_pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
        bigSpan->_n = NUM_PAGES - 1;
        _spanLists[bigSpan->_n].PushFront(bigSpan);
        return NewSpan(npage);
    }

public:
    std::mutex _pageMtx;

private:
    SpanList _spanLists[NUM_PAGES];
    objectMemoryPool<Span> _spanPool;

    std::unordered_map<PAGE_ID, Span *> _idSpanMap;
#ifdef _WIN64
    TCMalloc_PageMap1<64 - PAGE_SHIFT> _idSpanMap;
#elif _WIN32
    TCMalloc_PageMap1<32 - PAGE_SHIFT> _idSpanMap;
#endif
    PageCache()
    {
    }
    PageCache(const PageCache &) = delete;

    static PageCache _sInst;
};