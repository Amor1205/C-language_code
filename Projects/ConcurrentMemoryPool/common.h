#pragma once
#include <iostream>
#include <assert.h>
#include <thread>
using std::cout;
using std::endl;

static const size_t MAX_BYTES = 256 * 1024;
static const size_t NUM_FREELISTS = 256;
// common function
static void *&NextObj(void *obj)
{
    return *(void **)obj;
}

class FreeList
{
public:
    void Push(void *obj)
    {
        assert(obj);
        NextObj(obj) = _freeList;
        _freeList = obj;
    }
    void *Pop()
    {
        assert(_freeList);
        // head pop
        void *obj = _freeList;
        _freeList = NextObj(obj);
        return obj;
    }
    bool Empty()
    {
        return _freeList == nullptr;
    }

private:
    void *_freeList = nullptr;
};

class sizeClass
{
public:
    static inline size_t _roundup(size_t size, size_t alignmentNum)
    {
        return ((size + alignmentNum - 1) & ~(alignmentNum - 1));
    }
    static inline size_t roundUp(size_t size)
    {
        if (size <= 128)
        {
            _roundup(size, 8);
        }
        else if (size <= 1024)
        {
            _roundup(size, 16);
        }
        else if (size <= 8 * 1024)
        {
            _roundup(size, 128);
        }
        else if (size <= 64 * 1024)
        {
            _roundup(size, 1024);
        }
        else if (size <= 256 * 1024)
        {
            _roundup(size, 8 * 1024);
        }
        else
        {
            assert(false);
            return -1;
        }
    }
    static inline size_t _index(size_t size, size_t align_shift)
    {
        return (((size + (1 << align_shift) - 1)) >> align_shift) - 1;
    }
    static inline size_t index(size_t size)
    {
        assert(size <= MAX_BYTES);
        static size_t gourpNum[4] = {16, 72, 128, 184};
        if (size <= 128)
            return _index(size, 3);
        else if (size <= 1024)
            return _index(size - 128, 4) + gourpNum[0];
        else if (size <= 8 * 1024)
            return _index(size - 1024, 7) + gourpNum[1];
        else if (size <= 64 * 1024)
            return _index(size - 8 * 1024, 10) + gourpNum[2];
        else if (size <= 256 * 1024)
            return _index(size - 64 * 1024, 13) + gourpNum[3];
        else
        {
            assert(false);
            return -1;
        }
    }
};