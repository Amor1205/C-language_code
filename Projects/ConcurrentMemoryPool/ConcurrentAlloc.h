#pragma once
#include"common.h"
#include"threadCache.h"


static void* ConcurrentAlloc(size_t size)
{
    if(pthreadCache == nullptr)
    {
        pthreadCache = new ThreadCache;
    }
    return pthreadCache->Allocate(size);
}
static void ConcurrentDealloc(void* ptr, size_t size)
{
    assert(pthreadCache);
    pthreadCache->Deallocate(ptr,size);
}