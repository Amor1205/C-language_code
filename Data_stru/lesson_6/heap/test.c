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
//进行堆排序
void HeapSort(int *a, int n)
{
    //方法一
    // for (int i = 1; i < n;i++)
    // {
    //     AdjustUp(a, i);
    // }
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) // n为数组中元素个数而非最后一位的下标
    {
        AdjustDown(a, n, i);
    }

    //标记最后一位的位置，方便后面的删除
    //依次选数，调堆
    int pos = n - 1;
    while (pos--)
    {
        HeapSwap(a + 0, a + pos);
        //选出次小的数
        AdjustDown(a, pos, 0);
    }
}
int main()
{
    int a[] = {70, 56, 30, 25, 15, 10, 75};

    return 0;
}
