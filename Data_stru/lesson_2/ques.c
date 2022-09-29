//给有序数组nums，原地删除重复出现的元素，并且使每个元素只出现一次，返回删除后数组的新长度
//不要使用额外的数组空间，必须在原地修改输入数组并在使用O（1）额外空间的条件下完成

// e.g.
// input nums=[0,0,1,1,1,2,2,3,3,4]
// output  5,nums = [0,1,2,3,4]
int removeDuplicates(int *nums, int numsSize)
{
    int src = 0;
    int dst = 0;
    while (dst < numsSize)
    {
        if (nums[src] == nums[dst])
        {
            dst++;
        }
        else
        {
            src++;
            nums[src] = nums[dst];
            dst++;
        }
    }
    return src + 1;
}

// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

//归并排序
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int s1 = m - 1;
    int s2 = n - 1;
    int end = m + n - 1;
    while (s1 >= 0 && s2 >= 0)
    {
        if (nums1[s1] > nums2[s2])
        {
            nums1[end--] = nums1[s1--];
        }
        else
        {
            nums1[end--] = nums2[s2--];
        }
    }
    while (s2 >= 0)
    {
        nums1[end--] = nums2[s2--];
    }
}