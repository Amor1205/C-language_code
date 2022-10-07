#include "heap.h"
void HeapInit(HP *hp)
{
    assert(hp);
    hp->a = NULL;
    hp->size = hp->capacity = 0;
}
void HeapSwap(HPDataType *px, HPDataType *py)
{
    HPDataType tmp = *px;
    *px = *py;
    *py = tmp;
}

void HeapDestroy(HP *hp)
{
    assert(hp);
    free(hp->a);
    hp->capacity = hp->size = 0;
}
void AdjustUp(int *a, int child) // child = hp->size
{
    assert(a);
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] > a[parent])
        {
            HeapSwap(&a[child], &a[parent]);
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
}
//假设实现大堆
// int SearchForBigChild(int parent,int size)
// {
//     int smallChild = parent * 2 + 1;
//     int bigChild = parent * 2 + 2;
//     //有右孩子
//     if (bigChild < size)
//     {
//         bigChild = smallChild > bigChild ? smallChild : bigChild;
//     }
//     //只有一个孩子
//     else
//         bigChild = smallChild;

//     return bigChild;
// }
// //默认大堆
// void AdjustDown(int *a, int size, int parent)
// {
//     assert(a);
//     HeapSwap(&a[parent], &a[size - 1]);
//     int bigChild = SearchForBigChild(parent, size);
//     while (bigChild < size)
//     {
//         if (a[parent] < a[bigChild])
//         {
//             HeapSwap(&a[parent], &a[bigChild]);

//             parent = bigChild;
//             bigChild = SearchForBigChild(parent, size);
//         }
//         else
//             break;
//     }
// }

void AdjustDown(int *a, int size, int parent)
{
    assert(a);
    int child = parent * 2 + 1;
    while (child < size)
    {
        //选出左右孩子中大的那个
        if (child + 1 < size && a[child + 1] > a[child])
        {
            child++;
        }
        //如果大的孩子 大于 父亲，交换
        if (a[child] > a[parent])
        {
            HeapSwap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapPop(HP *hp)
{
    //只能删除堆顶的数据
    assert(hp);
    assert(!HeapEmpty(hp));
    //对换
    HeapSwap(&hp->a[0], &hp->a[hp->size - 1]); //最后一个数据是size-1
    hp->size--;
    AdjustDown(hp->a, hp->size, 0);
}
bool HeapEmpty(HP *hp)
{
    assert(hp);
    return hp->size == 0;
}
int HeapSize(HP *hp)
{
    assert(hp);
    return hp->size;
}
void HeapPrint(HP *hp)
{
    assert(hp);
    for (int i = 0; i < sizeof(hp->a) / sizeof(hp->a[0]); i++)
    {
        printf("%d ", hp->a[i]);
    }
}
void HeapDestroy(HP *hp)
{
    free(hp->a);
    hp->size = hp->capacity = 0;
}

HPDataType HeapTop(HP *hp)
{
    assert(hp);
    assert(!HeapEmpty(hp));
    return hp->a[0];
}
