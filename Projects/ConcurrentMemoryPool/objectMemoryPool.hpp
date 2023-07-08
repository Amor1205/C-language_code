#pragma once
#include"common.h"

// method1
// template<size_t N>
// class objectMemoryPool
// {};

// method2
template <class T>
class objectMemoryPool
{
public:
    T *New()
    {
        // Prioritise the use of returned memory blocks
        T *obj = nullptr;
        if (_freeList)
        {
            void *next = *((void **)_freeList);
            obj = (T*)_freeList;
            _freeList = next;
        }
        else
        {
            // cannot New a new T
            if (_remainingBytes < sizeof(T))
            {
                _remainingBytes = 128 * 1024;
                // _memory = (char *)malloc(128 * 1024);
                _memory = (char *)SystemAlloc(_remainingBytes >> 13);
                // _remainingBytes += 128 * 1024;
                if (_memory == nullptr)
                {
                    throw std::bad_alloc();
                }
            }

            // use T* obj to record the address
            obj = (T *)_memory;
            size_t objSize = sizeof(T) < sizeof(void *) ? sizeof(void *) : sizeof(T);
            _memory += objSize;
            _remainingBytes -= objSize;
        }

        new (obj) T;
        return obj;
    }
    void Delete(T* obj)
    {
        obj->~T();
        // head insert
        *(void **)obj = _freeList;
        _freeList = obj;

    }

private:
    char *_memory = nullptr;    // pointing to entire memory
    size_t _remainingBytes = 0; // the remaining bytes of entire memory
    void *_freeList = nullptr;  // the pointer of returning memory in free list
};
