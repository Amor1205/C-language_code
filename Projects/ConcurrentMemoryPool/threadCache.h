#include "common.h"

class ThreadCache
{
public:
    // request memory
    void *Allocate(size_t size)
    {
        assert(size <= MAX_BYTES);
        size_t alignSize = sizeClass::roundUp(size);
        size_t index = sizeClass::index(size);
        if (!_freeLists[index].Empty())
        {
            return _freeLists[index].Pop();
        }
        else
        {
            FetchFromCentralCache(index, alignSize);
        }
    }
    // release memory
    void Deallocate(void *ptr, size_t size)
    {
        assert(ptr);
        assert(size <= MAX_BYTES);
        // find index and push into freelist
        size_t index = sizeClass::index(size);
        _freeLists[index].Push(ptr);
    }
    void *FetchFromCentralCache(size_t index, size_t size);

private:
    FreeList _freeLists[NUM_FREELISTS];
};
// TLS thread local storage
static __declspec(thread) ThreadCache *pthreadCache = nullptr;