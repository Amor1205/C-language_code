#include "heap.h"
void PrintTopK(int *a, int n, int k)
{
    HP hp;
    HeapInit(&hp);
    //创建K个数的小堆
    for (int i = 0; i < k; ++i)
    {
        HeapPush(&hp, a[i]);
    }
    //剩下N-K个数与堆顶数据比较，比他大就替换他进堆
    for (int i = k; i < n; i++)
    {
        if (a[i] > HeapTop(&hp))
        {
            HeapPop(&hp);
            HeapPush(&hp, a[i]);
        }
    }
    HeapPrint(&hp);
    HeapDestroy(&hp);
}
int main()
{
    int a[] = {70, 56, 30, 25, 15, 10, 75};

    return 0;
}
