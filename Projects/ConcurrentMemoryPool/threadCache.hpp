#include "common.hpp"
#include "centralCache.hpp"
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

        if(_freeLists[index].Size() >= _freeLists[index].MaxSize())
        {
            ListTooLong(_freeLists[index], size);
        }
    }
    void *FetchFromCentralCache(size_t index, size_t size)
    {
        size_t batchNum = std::min(_freeLists[index].MaxSize(), sizeClass::NumMoveSize(size));
        if (batchNum == _freeLists[index].MaxSize())
        {
            _freeLists[index].MaxSize()++;
        }
        void *begin = nullptr;
        void *end = nullptr;
        size_t actualNum = CentralCache::getInstance()->FetchRangeObj(begin, end, batchNum, size);
        assert(actualNum);
        if(actualNum == 1)
            assert(begin == end);
        else
            _freeLists[index].PushRange(NextObj(begin), end, actualNum - 1);
        return begin;
    }
    void ListTooLong(FreeList& list, size_t size)
    {
        void *begin = nullptr;
        void *end = nullptr;
        list.PopRange(begin, end, list.MaxSize());

        CentralCache::getInstance()->ReleaseListToSpans(begin, size);

    }

private:
    FreeList _freeLists[NUM_FREELISTS];
};
// TLS thread local storage
static _declspec(thread) ThreadCache *pthreadCache = nullptr;
