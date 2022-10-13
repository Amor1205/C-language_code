#include "sort.h"
//假设排序都为升序
void SingleInsertSort(int *a, int n)
{
    assert(a);
    //要插入的数比这个数大，放在这个数后面
    //不知道end和x是多少，空着不谈。
    int end;
    int x;
    while (end >= 0)
    {
        //比这个数小，这个数往后挪一个
        if (a[end] > x)
        {
            a[end + 1] = a[end];
            --end;
        }
        else
        {
            break;
        }
    }
    a[end + 1] = x;
}

void InsertSort(int *a, int n)
{
    assert(a);
    //进行循环，注意边界
    for (int i = 0; i < n - 1; i++)
    {
        //单趟的排序
        int end = i;
        int x = a[end + 1];
        while (end >= 0)
        {
            if (a[end] > x)
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = x;
    }
}
//单趟预排序
void ShellSort(int *a, int n)
{
    //按gap分组，堆数据进行预排序
    //单趟的 只是拍了a[0] 、 a[3]这两个数
    //如果要排end end+gap end+2*gap ... 我们需要再写一个循环
    int gap = 3;
    int end = 0;
    int x = a[end + gap];
    while (end >= 0)
    {
        if (a[end] > x)
        {
            a[end + gap] = a[end];
            end -= gap;
        }
        else
        {
            break;
        }
    }
    a[end + gap] = x;
}

void ShellSort(int *a, int n)
{
    //按gap分组，堆数据进行预排序
    //单趟的 只是拍了a[0] 、 a[3]这两个数
    //如果要排end end+gap end+2*gap ... 我们需要再写一个循环
    int gap = 3;
    for (int i = 0; i < n - gap; i += gap)
    {
        int end = i;
        int x = a[end + gap];
        while (end >= 0)
        {
            if (a[end] > x)
            {
                a[end + gap] = a[end];
                end -= gap;
            }
            else
            {
                break;
            }
        }
        a[end + gap] = x;
    }
    //循环写好了，但是这只是a[0]/a[3]/a[6]/a[9]
    //需要写好整个数组的排列，就需要再套一层循环来调节end的值
}

//最终
void ShellSort(int *a, int n)
{
    //按gap分组，堆数据进行预排序
    //单趟的 只是拍了a[0] 、 a[3]这两个数
    //如果要排end end+gap end+2*gap ... 我们需要再写一个循环
    //循环写好了，但是这只是a[0]/a[3]/a[6]/a[9]
    //需要写好整个数组的排列，就需要再套一层循环来调节end的值
    int gap = 3;
    for (int j = 0; j < gap; j++)
    {
        for (int i = j; i < n - gap; i += gap)
        {
            int end = i;
            int x = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > x)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = x;
        }
    }
}
//多组一锅炖
void ShellSort(int *a, int n)
{
    //多次预排序(gap>1) + 直接插入(gap==1)
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 2;
        // gap = gap / 3 + 1;//预排序少一些，但是可能会出现2/3 = 0 的情况，所以需要加1.
        //保证到1是因为gap=1时才可以直接插入。
        for (int i; i < n - gap; i++)
        {
            int end = i;
            int x = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > x)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = x;
        }
    }
}
//最简单的
//遍历一遍选出最大放到最后
//再遍历一遍选出剩下的最大的放到后面，以此类推
//这样很慢！O（N2）
//我们尝试用一次选一个最大的和一个最小的，这样就把效率提升一倍，但总体来说还是很慢
void Swap(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
void SeletSort(int *a, int n)
{
    int begin = 0, end = n - 1;
    //我们在这里需要选择的是最小值和最大值的下标，否则一旦将其覆盖掉就不清楚了。
    while (begin < end)
    {
        int min = begin, max = begin;
        for (int i = begin; i <= end; i++)
        {
            if (a[i] < a[min]) //如果a[i]最小
            {
                //记录下标
                min = i;
            }
            if (a[i] > a[max])
            {
                max = i;
            }
            //交换
            // Swap(&a[begin], &a[min]);
            // Swap(&a[end], &a[max]);
            //这里会出问题，如果max就是他的begin，begin和max重叠了，明明a[min]和a[begin]已经换过了，但是因为max下标没动，导致初始位置又和end发生交换了。
            Swap(&a[begin], &a[min]);
            if (begin == max)
            {
                max = min;
            }
            Swap(&a[end], &a[max]);
        }
        begin++;
        end--;
    }
}

void HeapSort(int *a, int n)
{
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end--, 0);
    }
}
void BubbleSort(int *a, int n)
{
    //冒泡排序就是前一个比后一个大就交换
    for (int j = 0; j < n; j++)
    {
        int exchange = 0;
        for (int i = 1; i < n - j; i++)
        {
            if (a[i - 1] > a[i])
            {
                exchange = 1;
                Swap(a[i - 1], a[i]);
            }
            i++;
        }
        if (exchange)
        {
            break;
        }
    }
}

int GetMidIndex(int *a, int left, int right)
{
    // int mid = (left + right) / 2;
    int mid = left + (right - left) / 2; //减少溢出
    // int mid = left + ((right-left)>>1);//移位和上面的没差别，但是移位运算优先级低，要注意加括号。
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
            return mid;
        else if (a[right] < a[left])
            return left;
        else
            return right;
    }
    else
    {
        if (a[mid] > a[right])
            return mid;
        else if (a[left] > a[right])
            return right;
        else
            return left;
    }
}
int PartQuickSort(int *a, int left, int right)
{
    //三数取中
    int mid = GetMidIndex(a, left, right);
    Swap(&a[mid], &a[left]);
    int key = left;
    //单趟
    //找到比key小的值
    while (right > left)
    {
        //左边先走
        while (right > left && a[right] >= a[key])
        {
            right--;
            //如果面临 5 6 7 8 9 的情况
            //就会排序排出去加个判断
        }
        while (right > left && a[left] <= a[key])
        {
            left++;
        }
        Swap(&a[right], &a[left]);
    }
    Swap(&a[right], &a[key]);
    return right;
}

void QuickSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    //快排的小区间优化，当分割到小区间后，不再用递归分割思想让这段子区间有序
    //对于递归快排，减少递归次数
    if (right - left + 1 < 10)
    {
        InsertSort(a + left, right - left + 1);
    }
    int key = PartQuickSort(a, left, right);
    QuickSort(a, left, key - 1);
    QuickSort(a, key + 1, right);
}

int Partion(int *a, int left, int right)
{
    //三数取中
    int mid = GetMidIndex(a, left, right);
    Swap(&a[mid], &a[left]);
    int key = a[left];
    int hole = left;
    while (right > left)
    {
        while (a[right] >= key && right > left)
        {
            right--;
        }
        a[hole] = a[right];
        hole = right;
        while (left < right && a[left] <= key)
        {
            left++;
        }
        a[hole] = a[left];
        hole = left;
    }
    a[hole] = key;
    key = hole;
    return key;
}

int PrevCurPointer(int *a, int left, int right)
{
    //三数取中
    int mid = GetMidIndex(a, left, right);
    Swap(&a[mid], &a[left]);
    int key = left;

    int prev = left;
    int cur = left + 1;
    while (cur <= right)
    {
        if (a[cur] <= a[key])
        {
            Swap(a[cur], a[prev++]);
        }
        else
        {
            cur++;
        }
    }
    Swap(&a[prev], &a[key]);
    return prev;
}
//用栈
void QuickSortNonR(int *a, int left, int right)
{
    ST st;
    StackInit(&st);
    StackPush(&st, left);
    StackPush(&st, right);
    while (!StackEmpty(&st))
    {
        int end = StackTop(&st);
        StackPop(&st);
        int begin = StackTop(&st);
        StackPop(&st);

        int key = Pariton(a, begin, end);

        if (key + 1 < end)
        {
            StackPush(&st, key + 1);
            StackPush(&st, end);
        }
        if (begin < key - 1)
        {
            StackPush(&st, begin);
            StackPush(&st, key);
        }
    }
    StackDestroy(&st);
}
void _MergeSort(int *a, int left, int right, int *tmp)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    // [left, mid] [mid+1, right]
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int tmpleft = left;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
        {
            tmp[tmpleft++] = a[begin1++];
        }
        else
        {
            tmp[tmpleft++] = a[begin2++];
        }
    }
    while (begin1 <= end1)
    {
        tmp[tmpleft++] = a[begin1++];
    }
    while (begin2 <= end2)
    {
        tmp[tmpleft++] = a[begin2++];
    }
    // tmp 数组拷贝回a
    for (int j = left; j <= right; j++)
    {
        a[j] = tmp[j];
    }
}
void MergeSort(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror(malloc);
        exit(-1);
    }
    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
    tmp = NULL;
}

void MergeSortNonR(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror(malloc);
        exit(-1);
    }
    int gap = 1;
    while (gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap) // [i ~ i+gap-1] [i+gap ~ i+gap*2-1]
        {
            int begin1 = i, end1 = (i + gap - 1) < n ? (i + gap - 1) : (n - 1);
            int begin2 = (i + gap) < n ? (i + gap) : (n - 1), end2 = (i + gap * 2 - 1) < n ? (i + gap * 2 - 1) : (n - 1);
            int index = 0;
            // end1越界，begin2，end2不存在
            // begin2,end2 不存在

            while (begin1 <= end1 && begin2 <= end2)
            {
                if (begin1 < begin2)
                {
                    tmp[index++] = a[begin1++];
                }
                else
                {
                    tmp[index++] = a[begin2++];
                }
            }
            while (begin1 <= end1)
            {
                tmp[index++] = a[begin1++];
            }
            while (begin2 <= end2)
            {
                //如果是[8,8] [8,8]的情况，即begin1 = end1 , begin2 = end2
                // index会越界加条件判断
                if (index >= end2)
                    break;
                tmp[index++] = a[begin2++];
            }
        }
        gap *= 2;
    }
    //归并数组数据拷贝回原数组
    for (int j = 0; j <= n - 1; j++)
    {
        a[j] = tmp[j];
    }
    free(tmp);
    tmp = NULL;
}

void MergeSortNonR2(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror(malloc);
        exit(-1);
    }
    int gap = 1;
    while (gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap) // [i ~ i+gap-1] [i+gap ~ i+gap*2-1]
        {
            int begin1 = i, end1 = (i + gap - 1);
            int begin2 = (i + gap), end2 = (i + gap * 2 - 1);
            int index = 0;
            // end1越界，或者 begin2越界
            if (end1 > n || begin2 > n)
            {
                break;
            }
            // end2越界
            if (end2 > n)
            {
                end2 = n - 1;
            }
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (begin1 < begin2)
                {
                    tmp[index++] = a[begin1++];
                }
                else
                {
                    tmp[index++] = a[begin2++];
                }
            }
            while (begin1 <= end1)
            {
                tmp[index++] = a[begin1++];
            }
            while (begin2 <= end2)
            {
                tmp[index++] = a[begin2++];
            }

            //归并数组数据拷贝回原数组
            for (int j = i; j <= end2; j++)
            {
                a[j] = tmp[j];
            }
        }
        gap *= 2;
    }

    free(tmp);
    tmp = NULL;
}

void CountSort(int *a, int n)
{
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    int range = max - min + 1;
    int *count = (int *)malloc(sizeof(int) * range);
    memset(count, 0, sizeof(int) * range);
    if (!count)
    {
        perror(malloc);
        exit(-1);
    }
    //统计次数
    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }
    //根据次数进行排序
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i]--)
        {
            a[j++] = i + min;
        }
    }
}