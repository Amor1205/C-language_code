#pragma once

#include"common.h"


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
        return nullptr;
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

private:
    SpanList _spanLists[NUM_FREELISTS];

private:
    CentralCache()
    {}
    CentralCache(const CentralCache &) = delete;

    static CentralCache _sInst;

};