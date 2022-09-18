#include<stdio.h>
#include<string.h>
// 1.
//  void GetMemory(char *p) //str传到p，p是str的一份临时拷贝（形参）
//  {
//      p = (char *)malloc(100);//申请了100个字节的内存。放到p的起始地址
//      //对p的修改是不会影响str的。
//      //完成getmemory后，还发生了内存泄漏
//  }
//  void Test(void)
//  {
//      char *str = NULL;
//      GetMemory(str);//p销毁了，无人知道申请的起始地址了。
//      strcpy(str, "hello world");//对空指针解应用，程序崩溃
//      printf(str);//?
//      //printf中传递过去的是地址，所以直接传地址是可以的。
//  }
//  int main()
//  {
//      Test();
//      return 0;
//  }
//代码挂掉了，崩溃了。
//
//如何修改正确
//  void GetMemory(char **p)
//  {
//      *p = (char *)malloc(100);
//  }
//  void Test(void)
//  {
//      char *str = NULL;
//      GetMemory(&str);//这里传递str的指针过去
//      strcpy(str, "hello world");
//      printf(str);
//      free(str);
//      str = NULL;
//  }
//  int main()
//  {
//      Test();
//      return 0;
//  }

// char* Getmemory(void)
// {
//     char p[] = "hello world";
//     return p;
// }
// void Test(void)
// {
//     char *str = NULL;
//     str = Getmemory();//局部变量回收了，传输的只是一个地址，但是helloworld已经销毁了，就是野指针。
//     printf(str);//访问野指针，不可以。
// }
// int main()
// {
//     Test();
//     return 0;
// }
//最终没有输出helloworld，输出的烫烫烫烫
//叫返回栈空间的地址的问题

//需要补充一点的是，返回栈空间的变量，没有问题
// 如下
// int test()
// {
//     int a = 10;
//     return a;
// }
// int main()
// {
//     int n = test();
//     printf("%d\n", n);//打印成功，10
//     return 0;
// }
// 这串代码没有问题，因为返回的是变量，变量出函数之后会先储存到寄存器中，然后再进行销毁。不会影响后面对n的赋值

// int* test()
// {
//     int a = 10;
//     return &a;
// }
// int main()
// {
//     int *p = test();
//     printf("%d\n", *p);
//     return 0;
// }
//可以打印出来，但是代码本身是错误的。
//p此时是野指针的。本质上错误

//3.
// void GetMemory(char** p,int num)
// {
//     *p = (char *)malloc(num);
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(&str, 100);
//     strcpy(str, "hello");
//     printf(str);
// }
// int main()
// {
//     Test();
//     return 0;
// }
//问题：可以打印hello，没有free，没有判断p是否为NULL

//4.
// void Test(void)
// {
//     char *str = (char *)malloc(100);
//     strcpy(str, "hello");
//     free(str);//free后并不能指向hello，str为野指针。
//     if(str !=NULL)//但野指针并不一定是空指针，所以应该可以判断通过
//     {
//         strcpy(str, "world");//给野指针解引用，崩溃
//         printf(str);
//     }
// }
// int main()
// {
//     Test();
//     return 0;
// }

//野指针的问题举例
// int *test(void)
// {
//     int *ptr;
//     *ptr = 10;
//     return ptr;
// }
//ptr都没有初始化就解引用赋值，此时ptr就是野指针