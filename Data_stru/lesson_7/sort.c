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
    int key = PartQuickSort(a, left, right);
    QuickSort(a, left, key - 1);
    QuickSort(a, key + 1, right);
}

void Partion(int *a, int left, int right)
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

void PrevCurPointer(int *a, int left, int right)
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
            Swap(a[cur++], a[prev++]);
        }
        else
        {
            cur++;
        }
    }
}