// complexity
//
#define size_t long
#define NULL (void *)0
//数据结构前言
//数据结构(data structure)是计算机存储、组织数据的方式，指的是相互之间存在一种或多种特定关系的数据元素的集合。
//通俗来讲，实现一些项目的时候，需要在内存中将数据存储起来。
//可以用很多种方式来存储。数组(方便，但是有限，扩容麻烦)、链表(方便、直接指针)、树()
//算法(Algorithm)：就是定义良好的计算过程，去一个或者一组的值为输入，并产生出一个或者一组值作为输出。简单来说算法就是一系列的计算步骤，用来将输入数据转化为输出结果。
//比如，排序，查找，去重，推荐

//刷题：剑指offer 和 程序员代码面试指南
//《leetcode》
// 在牛客网可以做

//算法的复杂度
// 1.算法效率
// 1.1 如何衡量算法的好坏
//时间复杂度（算法运行速度）和空间复杂度（算法运行的额外空间）
//如今不再特别关注空间复杂度
//
//时间复杂度的概念：
//算法的时间复杂度是一个函数，它定量描述了该算法的运行时间。一个算法执行所耗费的时间，从理论上说，是不能算出来的，只有把程序放在机器上跑起来才能知道。
//但是每个程序都上机特别麻烦，所以有了时间复杂度的分析方式。
//一个算法所花费的时间与其中逾矩的执行次数成正比例，算法中的基本操作的执行次数，为算法的时间复杂度。
//即：找到某条基本语句与问题规模N之间的数学表达式，就是算出了该算法的时间复杂度。
//
//实际的计算时，只需要估算。大O的渐进表示法，只考虑最重要的一项
// O(N^2)    O代表括号内是估算，而并非准确表示
//大O符号(Big O notation): 是用于描述函数渐进行为的数学符号
//推到大O阶方法：
// 1.用常数1取代运行时间中的所有加法常数。(忽略加法)
// 2.在修改后的运行次数函数中，只保留最高阶项。(忽略低次)
// 3.如果最高阶项存在且不是1，则去除与这个项目相乘的常数。得到的结果就是大O阶(忽略高阶系数)
//一般情况下时间复杂度计算时未知数都使用的N，但是也可以是别的，如M、K等等其他的。
//
//比如：2N+10 -> O(N)  ， 可以看作是求N趋近于∞时的极限
// M+N -> O(M+N) ， 如果没有说明就是O(M+N),如果有说明，比如M>>N， O(M)
// 100 -> O(1) , O(1)并非是算法运算一次而是运算常数次
//
// const char* strchr (const char* str, int character);
// while(*str)
// {
//     if(*str == character)
//         return str;
//     else
//         ++str;
// }

//计算strchr的时间复杂度
//可以发现基本分为三种情况：
//最好情况(一进来就找到了，任意输入规模的最小运行次数（下届）)
//平均情况(任意输入规模的期望运行次数)
//最坏情况(人一输入规模的最大运行次数(上界))

//字符串不知道是多少的时候默认为N
//所以最好： 1 ， 平均： N/2， 最坏： N
//！！！：当一个算法随着输入不同，时间复杂度不同，时间复杂度做悲观预期，看最坏的情况。
//一般不会算平均，
//
//冒泡排序BubbleSort的时间复杂度
// 看思路，第一次比较了n次，第二次n-1次 ....1次
// 相加：n*(n+1)/2
// F(N) = N*(N+1)/2
// O(N*N)

//算时间复杂度不能只去看是几层循环，而要看他的思想
//二分查找
// int BinarySearch(int *a, int n, int x)
// {
//     assert(a);
//     int begin = 0;
//     int end = n;
//     while (begin < end)
//     {
//         int mid = begin + ((end - begin) >> 1);
//         if (a[mid] < x)
//             begin = mid + 1;
//         else if (a[mid] > x)
//             end = mid;
//         else
//             return mid;
//     }
//     return -1;
// }
//最好的情况O(1)
//最坏情况：找不到
//假设查找x次 ，找一次就是把区间二分，就是除二，其实就是2^x = N
// x = log2N
// 所以O(log2(N))

//二分查找算法是非常牛逼的算法
// N个数据中查找，N=1000，大概查找log2(1000)次数 -> 10
// N=1000*1000，->20
//但是二分查找需要排序，排序消耗的很大。
//
//树 -> 二叉树 -> 搜索二叉树 ->平衡搜索二叉树 -> AVLTree RbTree
//哈希表、B树系列
//

//计算阶乘递归Fac的时间复杂度
// long long Fac(size_t N)
// {
//     if(0==N)
//     {
//         return 1;
//     }
//     return Fac(N - 1) * N;
// }
// Fac(N) -> Fac(N-1) -> ,,, -> Fac(1)
//递归算法时间复杂度：递归次数*每次递归调用的次数
// N*1 = N
// O(N)

//计算斐波那契数列Fib的时间复杂度？
// long long Fib(size_t N)
// {
//     if (N < 3)
//         return 1;
//     return Fib(N - 1) + Fib(N - 2);
// }
//递归调用的次数指的是递归为最初的情况
// Fib(N)   2^0
// Fib(N-1) Fib(N-2)  2^1
// Fib(N-2) Fib(N-3) Fib(N-3) Fib(N-4)  2^2
// 2^3
// Fib(0) Fib(1)       -> 2^(N-1) - x (缺一些东西，有的会提前递归结束)
//等比数列，递归调用： 2^0 + 2^1 + 2^(N-1) = 2^N - 1 - X
// O(2^N)

//指数的非常慢，可以发现，斐波那契数列的递归写法不要用递归写法，用循环写法

// 3.空间复杂度
//也是一个数学函数表达式，计算临时占用存储空间大小的量度。
//空间复杂度实际计算的是变量的个数。
//函数运行时所需要的栈空间（存储参数、局部变量、一些寄存器信息等）在编译期间已经确定好了，因此空间复杂度主要通过函数在运行时候显式申请的额外空间来确定。

//冒泡排序的空间复杂度：
// void BubbleSort(int*a,int n)
// {
//     assert(a);
//     for (size_t end = n; end > 0;--end)
//     {
//         int exchange = 0;
//         for (size_t i = 1; i < end;++i)
//         {
//             if(a[i-1]>a[i])
//             {
//                 Swap(&a[i - 1], &a[i]);
//                 exchange = 1;
//             }
//         }
//         if (exchange == 0)
//             break;
//     }
// }
//算的是额外的！！！
//这个代码里额外添加的是 ： end ， i ， exchange
// 3是 常数个，所以O(1)

// 2.计算Fibonacci的空间复杂度
//  返回Fibonacci数列的前n项
//  long long* Fibonacci(size_t n)
//  {
//      if(n==0)
//          return NULL;
//      long long *fibArray = (long long *)malloc((n + 1) * sizeof(long long));
//      fibArray[0] = 0;
//      fibArray[1] = 1;
//      for (int i = 2; i <= n;++i)
//      {
//          fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//      }
//      return fibArray;
//  }
//空间复杂度O(N)
//时间复杂度O(N)

// 3.计算阶乘递归Fac的空间复杂度
//
//  long long Fac(size_t N)
//  {
//      if(N==1)
//          return 1;
//      return Fac(N - 1) * N;
//  }
//  每次递归建立一个栈针，总共N个栈针
//  空间复杂度 O(N)

// 4.Fib递归空间复杂度
// O(N)
//空间是可以重复利用，不累计的。
//时间是一去不复返的，累计的。
//

// 3N^2 + 4n + 5  -> O(N^2)
// 3log(2)N + 4 -> O(log(2)N)
// 2n + 3nlog(2)n + 14 -> O(nlog(2)n)
// n^3 + 2n^2 + 4n + 6 -> O(n^3)

//面试题
//数组nums包含从0到n的所有整数，但其中缺了1个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//（规定了时间复杂度）

//思路1.排序，看后一个数是不是前面的数加1， 用qsort 是快排，时间复杂度O(n*logN)
//思路2. 0+1+2+3+....n - (a[0]+a[1]+...a[n-1]) -> O(N)
//思路3. 创建n+1的数组，数组中值是几就写在几的位置，找空着的那个值。(空间复杂度O(N)比较大)
//思路4. 给一个x=0，x先跟[0,n]的所有值亦或，在跟数组中的每个值亦或，最后x就是缺失的那个数字
//

//写一下思路2
// int FinfNum(int*arr,int n)
// {
//     //return n * (n + 1) / 2 - (arr[0] + arr[1] + arr[2] + ....arr[n]);
//     //这个是一步完不成的，需要用：
//     int ret = 0;
//     for (int i = 0; i < n;i++)
//     {
//         int sum = n * (n + 1) / 2;
//         sum -= arr[i];//0 -> n-1
//         i++;
//     }
//     return ret;
// }

//可以发现一道题有多种方法，那么我们不用实现，只需要分析出每种方法的复杂度，选取复杂度优的方法即可，这就是复杂度在实际中的意义。

//思路3
//思路4：
//两个相同的数亦或就没了，
//时间复杂度o(n),空间o(1)
// int missingNumber(int*nums,int numsSize)
// {
//     int x = 0;
//     //跟[0,n]异或
//     for (int i = 0; i <= numsSize;++i)
//     {
//         x ^= i;
//     }
//     //在跟数组异或
//     for (int i = 0; i < numsSize;++i)
//     {
//         x ^= nums[i];
//     }
//     return x;
// }
//

//旋转数组
//给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数
//
//尽可能想出更多的解决方案，至少三种不同的方法可以解决这个问腿。
//可以使用空间复杂度为O(1)的原地算法解决这个问题吗？

//示例： [1,2,3,4,5,6,7] k=1 -> [7,1,2,3,4,5,6]
//
//思路1. 创建一个新的数组，来接收不同位置的值(k后面的放在前面，k前面的放在后面)，时间复杂度O(N),空间复杂度O(N)
//思路2. 暴力求解，旋转k次 时间复杂度O(N*k) 空间复杂度O(1)
//思路3. 前n-k个逆置，后k个逆置，最后整体逆置 TO(N),SO(1)
//
//思路3
// void Reserve(int *nums, int left, int right)
// {
//     while (left < right)
//     {
//         int tmp = nums[left];
//         nums[left] = nums[right];
//         nums[right] = tmp;
//     }
//     ++left;
//     --right;
// }
// void rotate(int *nums, int numsSize, int k)
// {
//     if (k >= numsSize)
//         k %= numsSize;
//     // 前n-k个逆置
//     Reverse(nums, 0, numsSize - 1 - k);
//     //后k个逆置
//     Reverse(nums, numsSize - k, numsSize - 1);
//     //整体逆置
//     Reverse(nums, 0, numsSize - 1);
// }
//但是当k==n时，不旋转就是要的结果
// k>=n,实际上是多旋转了k的整数倍次
