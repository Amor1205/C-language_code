#include "heap.h"
void HeapInit(HP *hp)
{
    assert(hp);
    hp->a = NULL;
    hp->size = hp->capacity = 0;
}
void HeapDestroy(HP *hp)
{
    assert(hp);
    free(hp->a);
    hp->capacity = hp->size = 0;
}
void AdjustUp(int *a, int size, int child) // child = hp->size
{
    assert(a);
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] > a[parent])
        {
            HPDataType tmp = a[child];
            a[child] = a[parent];
            a[parent] = tmp;

            child = parent;
            parent = (child - 1) / 2;
        }
        else
            break;
    }
}
void HeapPush(HP *hp, HPDataType x)
{
    assert(hp);
    //实现增容
    if (hp->size == hp->capacity)
    {
        size_t newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
        HPDataType *tmp = (HP *)realloc(hp->a, sizeof(HP) * newCapacity);
        if (!tmp)
        {
            perror("malloc");
            exit(-1);
        }
        hp->a = tmp;
        hp->capacity = newCapacity;
    }
    //假设实现大堆
    AdjustUp(hp->a, hp->size, hp->size - 1);
}
void HeapPop(HP *hp);
void HeapPrint(HP *hp)
{
    assert(hp);
    for (int i = 0; i < sizeof(hp->a) / sizeof(hp->a[0]); i++)
    {
        printf("%d ", hp->a[i]);
    }
}