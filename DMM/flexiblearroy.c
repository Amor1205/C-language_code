#include <stdio.h>
#include <stdlib.h>
// struct S
// {
//     int num;
//     double d;
//     int arr[];//柔性数组成员，未知大小的最后一个成员
// };
// struct S2
// {
//     int num;
//     int arr[0];//或者数组里面写0
// };
// int main()
// {
//     printf("%d\n", sizeof(struct S));
//     return 0;
// }

//柔性数组的特点
// 1.结构体中的柔性数组前必须得有一个其他成员
// 2.sizeof返回的这种结构大小不包括柔性数组的内存
// 3.包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。
// struct S3
// {
//     int num;
//     int arr[];
// };
// int main()
// {
//     struct S3*ps = (struct S3*)malloc(sizeof(struct S3) + 40);//后面四十个字节给柔性数组arr
//     if (ps == NULL)
//     {
//         perror("realloc\n");
//         return 1;
//     }
//     ps->num = 100;
//     for (int i = 0; i < 10;i++)
//     {
//         ps->arr[i] = i;
//     }
//     for (int i = 0; i < 10;i++)
//     {
//         printf("%d\n", ps->arr[i]);
//     }
//     //扩容
//     struct S3 *ptr = (struct S3 *)realloc(ps, sizeof(struct S3) + 80);
//     if(ptr == NULL)
//     {
//         perror("realloc\n");
//         return 1;
//     }
//     else
//         ps = ptr;
//     for (int i = 10; i < 20; i++)
//     {
//         ps->arr[i] = i;
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d\n", ps->arr[i]);
//     }
//     //释放
//     free(ps);
//     ps = NULL;
//     //
//     return 0;
// }

//不使用柔性数组，也可以进行结构体的可大可小
//但是如下的实现与柔性数组有差别，
//下面的实现中，num与arr的地址并不连续
// struct S4
// {
//     int num;
//     int *arr;
// };
// int main()
// {
//     struct S4 *ps = (struct S4 *)malloc(sizeof(struct S4));
//     is(ps == NULL)
//     {
//         return 1;
//     }
//     ps->arr = (int *)malloc(40);
//     if(ps->arr == NULL)
//     {
//         free(ps);
//         ps = NULL;
//         return 1;
//     }

//     free(ps->arr);
//     ps->arr = NULL;

//     free(ps);
//     ps = NULL;
//     return 0;
// }

//柔性数组的好处就出来了
// 1.访问速度快， 因为结构体中的数组连续存放 （减少内存碎片）
// 2.释放内存方便，只需要一次。
