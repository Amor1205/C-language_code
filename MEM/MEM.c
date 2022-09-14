#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <memory.h>
// 1.memcpy - 内存拷贝,头文件memory.h
// mem-memory - 记忆 - 内存
// cpy-copy - 复制
// void * memcpy(void*dest,const void*src,size_t num)//num->拷贝多少个字节
//内存拷贝，不知道用这个函数拷贝什么类型的数据，所以用泛型指针。
// void *my_memcpy(void *dest, const void *src, size_t num)
// {
//     assert(dest && src);
//     void *ret = dest;
//     // for (int i = 0; i < num; i++)
//     // {
//     //     *(char *)dest++ = *(char *)src++;
//     // }
//     while (num--)
//     {
//         *(char *)dest = *(char *)src;
//         dest = (char *)dest + 1;
//         src = (char *)src + 1;
//     }
//     return ret;
// }
// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7};
//     int arr2[10] = {0};
//     my_memcpy(arr2, arr1, 28);
//     // 4*7 = 28
//     return 0;
// }
//注意，memcpy 负责拷贝凉快独立空间中的数据
// memmove 可以进行重叠内存的拷贝
// void* memmove(void* dest,const void* src,size_t num)
// void *my_memmove(void *dest, const void *src, size_t num)
// {
//     assert(dest && src);
//     void *ret = dest;
//     //有的时候从前向后拷贝，有的时候从后向前拷贝，判断
//     if (dest - src > 0) // dest在src后面
//     {
//         //需要从后往前拷贝
//         //    dest = (char *)dest + num - 1;
//         //    src = (char *)src + num - 1;
//         //    while (num--)
//         //    {
//         //        *(char *)dest = *(char *)src;
//         //        dest = (char *)dest - 1;
//         //        src = (char *)src - 1;
//         //    }
//         while (num--)
//         {
//             *((char *)dest + num) = *((char *)src + num);
//         }
//     }
//     else
//     {
//         while (num--)
//         {
//             *(char *)dest = *(char *)src;
//             dest = (char *)dest + 1;
//             src = (char *)src + 1;
//         }
//     }
//     return ret;
// }
// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     my_memmove(arr1 + 2, arr1, 20);
//     int a = 0;
//     while (a <= 9)
//     {
//         printf("%d\n", arr1[a]);
//         a++;
//     }
//     return 0;
// }

// 3.int memcpy(const void* ptr1, const void* ptr2,size_t num)
//  int main()
//  {
//      int arr1[] = {1, 2, 3, 4, 5};
//      int arr2[] = {1, 3, 2};
//      int ret = memcpy(arr1, arr2, 12);
//      printf("%d\n", ret);
//      return 0;
//  }

// 4.memset
// void* memset(void* ptr,int value,size_t num);
// ptr -> the block of memory to fill
//
// int main()
// {
//     // char arr[] = "hello bit";
//     // memset(arr+6, 'x', 3);
//     // printf("%s\n", arr);
//     int arr[10] = {0};
//     //若想把arr全部初始化为1；
//     memset(arr, 1, 40);//每个字节都变成了01，他是按照字节进行初始化的。
//     //所以不能拿memset去初始化整型数组。
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         printf("%d\n", arr[i]);
//     }
//         return 0;
// }