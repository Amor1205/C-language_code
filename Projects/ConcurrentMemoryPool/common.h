#pragma once
#include <iostream>
#include <assert.h>
#include <thread>
#include <algorithm>
#include <mutex>
using std::cout;
using std::endl;

#ifdef _WIN64
typedef long long PAGE_ID;
#elif _WIN32
typedef size_t PAGE_ID;
#elif __APPLE__
typedef long long PAGE_ID;
#endif

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
    void PushRange(void* begin, void* end)
    {
        assert(begin);
        NextObj(end) = _freeList;
        _freeList = begin;
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
    size_t& MaxSize()
    {
        return _maxSize;
    }

private:
    void *_freeList = nullptr;
    size_t _maxSize = 1;
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
    static size_t NumMoveSize(size_t size)
    {
        assert(size > 0);
        int num = MAX_BYTES / size;
        if(num < 2)
            return 2;
        else if(num > 512)
            return 512;
        else
            return num; 
    }
};

//manage continuous pages
class Span
{
public:
    PAGE_ID _pageid = 0; // Page id of the start page of the large block of memory
    size_t _n = 0;// num of page

    Span* _next = nullptr;
    Span *_prev = nullptr;

    size_t _useCount = 0; // num of small blocks of memory allocated
    void *_freeList = nullptr; 
};

class SpanList
{
public:
    SpanList()
    {
        _head = new Span;
        _head->_next = _head;
        _head->_prev = _head;
    }
    void Insert(Span* pos, Span* newSpan)
    {
        assert(pos);
        assert(newSpan);
        Span *prev = pos->_prev;
        prev->_next = newSpan;
        newSpan->_prev = prev;
        newSpan->_next = pos;
        pos->_prev = newSpan;
    }
    void Erase(Span* pos)
    {
        assert(pos);
        assert(pos != _head);

        Span *prev = pos->_prev;
        Span *next = pos->_next;

        prev->_next = next;
        next->_prev = prev;

    }

private:
    Span *_head;
public:
    std::mutex _mtx;
};