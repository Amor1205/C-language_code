#pragma once
#include "common.h"
#include "threadCache.h"
#include "pageCache.h"
#include"objectMemoryPool.h"

static void *ConcurrentAlloc(size_t size)
{
    if (size > MAX_BYTES)
    {
        // align
        size_t alignmentSize = sizeClass::roundUp(size);
        size_t npage = alignmentSize >> PAGE_SHIFT;

        PageCache::getInstance()->_pageMtx.lock();
        Span *span = PageCache::getInstance()->NewSpan(npage);
        span->_objSize = size;
        PageCache::getInstance()->_pageMtx.unlock();

        void *ptr = (void *)(span->_pageid << PAGE_SHIFT);
        return ptr;
    }
    if (pthreadCache == nullptr)
    {
        static objectMemoryPool<ThreadCache> tcPool;
        // pthreadCache = new ThreadCache;
         pthreadCache = tcPool.New();
    }
    return pthreadCache->Allocate(size);
}
static void ConcurrentDealloc(void *ptr)
{
    assert(ptr);
    Span *span = PageCache::getInstance()->MapObjToSpan(ptr);
    size_t size = span->_objSize;
    if (size > MAX_BYTES)
    {
        PageCache::getInstance()->_pageMtx.lock();
        PageCache::getInstance()->ReleaseSpanToPageCache(span);
        PageCache::getInstance()->_pageMtx.unlock();
    }
    else
    {
        assert(pthreadCache);
        pthreadCache->Deallocate(ptr, size);
    }
}
