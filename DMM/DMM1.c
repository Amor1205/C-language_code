// DMM-->Dynamic memory management
// 1.为什么存在动态内存分配
// 2.动态内存函数的介绍
//  malloc free calloc realloc
// 3.常见错误
// 4.题目
// 5.柔性数组

// malloc
// funtion -- allocate memory block
// allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
// void* malloc(size_t size);
// if error, return NULL;
//
#include <stdio.h>
#include <errno.h>
// int main()
// {
//     int arr[10] = {0};
//     //动态内存开辟
//     int*p = (int*)malloc(40);
//     if(p==NULL)
//     {
//         printf("%s\n", strerror(errno));//return 1 if error
//         return 1;
//     }
//     for (int i = 0; i < 10;i++)
//     {
//         *(p + i) = i;
//     }
//     for (int i = 0; i < 10;i++)
//     {
//         printf("%d\n", *(p + i));
//     }
//         // generally return 0 if successfully run
//         //确实没有free
//         //并不是说内存空间就不回收了
//         //当程序退出的时候，系统会自动回收内存空间。
//     free(p);
//     p = NULL;//一般free是要连着用两个，用free内存空间释放，用p=NULL让p不再记忆原本的初地址

//     return 0;
// }
//重要，
//如果要使用malloc，使用后要进行验证，以免报错
//使用的就是strerror
//内存泄漏 -- 占据了一些内存空间，但是永不会释放。
//变长数组 -- 支持int arr[n]的数组，在C99才支持，老版本编译器一般不支持
//
// calloc
// allocates an array in memory with elements initialized to 0;
//
// int main()
// {
//     //int *p = (int *)malloc(40);
//     //申请10个整形的空间
//     int* p = (int*)calloc(10, sizeof(int));//calloc申请的空间会被初始化为0
//     //malloc申请的空间不会被初始化
//     if(p == NULL)
//     {
//         perror("calloc");
//         return 1;
//     }
//     //use
//     for (int i = 0; i < 10;i++)
//     {
//         printf("%d ", *(p + i));
//     }
//     free(p);
//     p = NULL;
//     return 0;
// }

// realloc   re---alloc
// reallocate memory blocks
// void* realloc(void*memblock, size_t size);
// int main()
// {
//     int *p = malloc(40);
//     if(p ==NULL)
//     {
//         perror("malloc");
//         return 1;
//     }
//     for (int i = 0; i < 10;i++)
//     {
//         printf("%d ", *(p + i));
//     }
//     // free(p);
//     // p = NULL;
// //空间不够，希望能放20个元素，考虑扩容
// //
//     int*ptr = (int*)realloc(p, 80);
//     //20*4=80
//     //如果后面的空间够，则返回原来的地址
//     //如果空间不够用，后面的有一块区域被别人占用的话，会重新找到一块合适的空间，同时把之前的数据全部复制过来，同时让p指向新的地址。同时，realloc还会把之前的空间free掉。
//     //如果扩容失败，返回NULL，所以不能使用p来接收realloc的值
//     if(ptr!=NULL)
//     {
//         p = ptr;
//     }
//     //不再使用后
//     free(p);
//     p = NULL;

//     return 0;
// }
//必须要记住你的起始地址，如果你记不住起始地址，那么就内存泄漏了。因为你没法释放这块空间了
//可能会遇到的问题
// 1.对NULL指针的解引用操作
//解决办法：对malloc函数的返回值进行判断如line115-119
// int main()
// {
//     int *p = malloc(1000);
//     // if(p==NULL)
//     // {
//     //     perror("malloc");
//     //     return 1;
//     // }
//     for (int i = 0; i < 250;i++)
//     {
//         *(p + i) = i;
//     }
//         return 0;
// }

// 2.对动态开辟空间的越界访问
//解决办法：需要对内存边界主动的检查
//  int main()
//  {
//      int *p = (int *)mallco(100);
//      int i = 0;
//      if(p ==NULL)
//      {
//          perror("malloc");
//          return 1;
//      }
//      //使用
//      for (int i = 0; i <= 25;i++)//<= 25 循环26次，形成越界访问。
//      {
//          *(p + i) = i;
//      }
//      return 0;
//  }

// 3.对非动态开辟内存的free释放
//
//  int main()
//  {
//      int a = 10;
//      int *p = &a;
//      //使用p
//      free(p);//free只能释放动态内存
//      p = NULL;
//      return 0;
//  }

// 4.使用free来释放动态内存的一部分
//
// int main()
// {
//     int *p = (int *)malloc(100);
//     if (p == NULL)
//     {
//         return 1;
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         *p = i;
//         p++;
//     }
//     //释放空间
//     free(p);
//     p = NULL;
//     // error
//     return 0;
// }
//报错了。
//原因是p并未指向起始地址，不能从动态开辟内存的一半

// 5.对同一块动态内存多次释放
//  int main()
//  {
//      int *p = malloc(100);
//      if(p==NULL)
//      {
//          return 1;
//      }
//      free(p);
//      p = NULL;
//      free(p);//err
//      return 0;
//  }

// 6.动态开辟内存忘记释放（内存泄漏）
// void test()
// {
//     int *p = malloc(100);
//     //使用
// }
// int main()
// {
//     test();
//     while (1)
//     {
//         ;
//     }
//     return 0;
// }
//开辟了如果不释放，就会内存泄漏

// 5.C/c++程序开辟
//操作系统的基础知识
//
//内核空间（用户代码不能读写）
//栈区（向下增长）
//内存映射端（文件映射、动态库、匿名映射）
//堆区（向上增长）
//数据段（静态区）（全局变量、静态数据）
//代码段（可执行代码/只读常量）
//-------------------------------------
//数据段/静态区
//  int globalVar = 1;
//  static int staticGlobalVar = 1;
//-------------------------------------
//代码段 -->不能修改
//  char char2[] = "abcd";
//  char *pChar3 = "abcd";
//-------------------------------------
//堆
//  int *ptr1 = (int *)malloc(4);
