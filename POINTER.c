#include <stdio.h>
#include <string.h>
// int main()
//{
// example1.
//  (*(void(*)())0)();
//  void(*p)() -> 函数指针
//  (函数指针类型)0  -> 强制类型转换
//  把0强制类型转换为函数指针，再解引用，并执行函数

// example2.
//  void(* signal(int,void(*)(int)))(int);
// void(*signal - - )(int)
// 调用了函数指针 函数用变量为int和一个void(*)(int)的函数指针。
// 设想，如果signal是函数名，调用函数，后面不可能是类型而是参数
// 应该是函数的声明，这个函数的类型是void，调用int类型参数
// -------------
//想法错误

//因为 signal后面直接为(int,void(*)(int)),signal和括号先结合
//区别于函数指针，void(*singal)(int,void(*)(int))
// [括号位置不同]

//回顾函数声明， int Add(int,int) 类型，函数名，参数类型
//可以发现，这一行代码，就是函数声明。
//函数名为signal，第一参数的类型为int，第二个参数的类型为void(*)(int)
// signal函数的返回类型为一个函数指针，为void(*)(int)

//可以发现特别的繁琐，非常的难以理解
//可以使用typedef进行重命名。
//
// typedef void(*pf_t)(int);//把void(*)(int)类型重命名为pf_t
//可以写成
// pf_t signal(int,pf_t);
//进行了代码的简化
// return 0;
//}

//函数指针的用途

//简单实现计算器的功能
//加法 + 减法 + 乘法 + 除法
// void menu()
// {
//     printf("*****************************\n");
//     printf("******* 1.add    2.sub*******\n");
//     printf("******* 3.mul    4.div*******\n");
//     printf("************ 0.exit *********\n");
//     printf("*****************************\n");
// }
// int Add(int x, int y)
// {
//     return x + y;
// }
// int Sub(int x, int y)
// {
//     return x - y;
// }
// int Mul(int x, int y)
// {
//     return x * y;
// }
// int Div(int x, int y)
// {
//     return x / y;
// }
// int main()
// {
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     int ret = 0;
//     do
//     {
//         menu();
//         printf("please choose:>");
//         scanf("%d", &input);

//         switch (input)
//         {
//         case 1:
//             printf("please input 2 numbers:>");
//             scanf("%d %d", &x, &y);
//             ret = Add(x, y);
//             printf("%d\n", ret);
//             break;
//         case 2:
//             printf("please input 2 numbers:>");
//             scanf("%d %d", &x, &y);
//             ret = Sub(x, y);
//             printf("%d\n", ret);
//             break;
//         case 3:
//             printf("please input 2 numbers:>");
//             scanf("%d %d", &x, &y);
//             ret = Mul(x, y);
//             printf("%d\n", ret);
//             break;
//         case 4:
//             printf("please input 2 numbers:>");
//             scanf("%d %d", &x, &y);
//             ret = Div(x, y);
//             printf("%d\n", ret);
//             break;
//         case 0:
//             printf("quit the calculator\n");
//             break;
//         default:
//             printf("unfairly choose\n");
//             break;
//         }
//     } while (input);
//     return 0;
// }
//发现代码冗余
//我们可以设计一个函数可以实现上述加减乘除四个函数的功能
//定义为Calc函数
//传进各个函数的地址进行计算
//

// void Calc(int (*pf)(int, int))
// {
//     int x = 0;
//     int y = 0;
//     int ret = 0;

//     printf("please input 2 numbers");
//     scanf("%d %d", &x, &y);
//     ret = pf(x, y);
//     printf("%d", ret);
// }
// void menu()
// {
//     printf("*****************************\n");
//     printf("******* 1.add    2.sub*******\n");
//     printf("******* 3.mul    4.div*******\n");
//     printf("************ 0.exit *********\n");
//     printf("*****************************\n");
// }
// int Add(int x, int y)
// {
//     return x + y;
// }
// int Sub(int x, int y)
// {
//     return x - y;
// }
// int Mul(int x, int y)
// {
//     return x * y;
// }
// int Div(int x, int y)
// {
//     return x / y;
// }
// int main()
// {
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     int ret = 0;
//     do
//     {
//         menu();
//         printf("please choose:>");
//         scanf("%d", &input);

//         switch (input)
//         {
//         case 1:
//             Calc(Add);
//             break;
//         case 2:
//             Calc(Sub);
//             break;
//         case 3:
//             Calc(Mul);
//             break;
//         case 4:
//             Calc(Div);
//             break;
//         case 0:
//             printf("quit the calculator\n");
//             break;
//         default:
//             printf("unfairly choose\n");
//             break;
//         }
//     } while (input);
//     return 0;
// }

//什么时候比较倾向于使用函数指针呢？
//想要函数封装的时候

//函数指针数组: 存放函数指针的数组
// int (*pf)(int, int) = Add;                      // pf是函数指针
// int (*arr[4])(int, int) = {Add, Sub, Mul, Div}; // arr是函数指针数组

//指针数组: int* arr1[5]
//

// int Add(int x, int y)
// {
//     return x + y;
// }
// int Sub(int x, int y)
// {
//     return x - y;
// }
// int Mul(int x, int y)
// {
//     return x * y;
// }
// int Div(int x, int y)
// {
//     return x / y;
// }
// int main()
// {
//     int(*parr[4])(int,int) = {Add, Sub, Mul, Div};
//     for (int i = 0; i <= 4;i++)
//     {
//         int ret = parr[i](8, 4);
//         printf("%d ", ret);
//     }
//         return 0;
// }
//如果使用函数指针数组，可以极大简化上述计算器的代码。

// int main()
// {
//     int (*pArr[])(int, int) = {0, Add, Sub, Mul, Div};
//     int (*(*pfArr)[5])(int, int) = &pArr; //pfArr就是一个函数指针
//     return 0;
// }

//什么是回调函数
//回调函数：一个通过函数指针调用的函数。
//函数的指针或者地址作为参数传递个另外一个函数，当这个指针被用来调用其所指向的函数时，这就是回调函数。

// bubble sort 冒泡排序，只能排序整型数据
//
// void bubble_sort(int arr[], int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         int flag = 1;//假设数组是排好序的

//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//                 flag = 0;
//             }
//         }
//         if (flag == 0)
//         {
//             break;
//         }
//     }
// }
// bubble_sort只能排序整型
//库函数qsort 快速排序的思想实现的一个排序函数
//
// void qsort(void *base,//要排序的数据的起始位置
// size_t num, //带排序的数据元素的个数
// size_t width, //带排序的数据元素的大小
// int (*cmp)(const void *e1, const void *e2));//比较函数

// void* 是无具体类型的指针，所以不能解引用操作，也不能加减整数
//必须先强制类型转换。

// int cmp_int(const void *e1, const void *e2)
// {
//     return (*(int *)e1 - *(int *)e2);
//     // e1 > e2 时 返回值大于0；
// }

// int main()
// {
//     int arr[] = {9, 8, 7, 6, 5, 3, 4, 2, 1};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     //bubble_sort(arr, sz);
//     qsort(arr, sz, sizeof(arr) / sizeof(arr[0]), cmp_int);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// struct Stu
// {
//     char name[20];
//     int age;
// };
// int cmp_stu_by_name(const void *e1, const void *e2)
// {
//     return strcmp(((struct Stu *)e1)->name, ((struct Stu *)e2)->name);
// }
// //比较字符串：strcmp，对应的字符相比较，如果相等则比较下一对。
// void test2(void)
// {
//     struct Stu s[] = {{"zhangsan", 15}, {"lisi", 16}};
//     int sz = sizeof(s) / sizeof(s[0]);
//     qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
// }
// int main()
// {
//     test2();
//     return 0;
// }

//改造bubble sort函数
// void Swap(char *buf1, char *buf2, int width)
// {
//     for (int i = 0; i < width; i++)
//     {
//         char tmp = *buf1;
//         *buf1 = *buf2;
//         *buf2 = tmp;
//         buf1++;
//         buf2++;
//     }
// }
// int cmp(const void *e1, const void *e2)
// {
//     return *(int *)e1 - *(int *)e2;
// }
// void bubble_sort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
// {
//     int i = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         int flag = 1;
//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++)
//         {
//             if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
//             {
//                 Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
//             }
//         }
//     }
// }
// int mian()
// {
//     int arr[] = {9, 2, 4, 5, 6, 8, 1, 0};
//     bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
//     return 0;
// }

//题目：数组名的理解和指针的运算
// int main()
// {
//     int a[] = {1, 2, 3, 4};
//     printf("%d\n", sizeof(a));//16,单放一个数组名，代表整个数组
//     printf("%d\n", sizeof(a+0));//4(WIN86)/8(WIN64),是指针的大小。并非单独的数组名，也没有取地址，a代表数组首元素的地址。
//     printf("%d\n", sizeof(*a));//4，a<=>&a[0], a+0 <=> &a[0]+0, *a就是首元素的大小。
//     printf("%d\n", sizeof(a+1));//4/8，第二个元素的地址
//     printf("%d\n", sizeof(a[1]));//4，计算的是第二个元素所占的内存空间的大小(整型)
//     printf("%d\n", sizeof(&a));//4/8,&a取出数组的地址，但是只要是地址就是4/8字节的大小
//     printf("%d\n", sizeof(*&a));//16，*&消了（&a类型为int(*)[4]，再&是访问的一个数组）
//     printf("%d\n", sizeof(&a+1));//4/8，是从数组a的地址向后跳过整个数组的地址
//     printf("%d\n", sizeof(&a[0]));//4/8，数组第一个元素的地址
//     printf("%d\n", sizeof(&a[0]+1));//4/8，计算的是数组第二个元素的地址

//     return 0;
// }

// int main()
// {
//     char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};

//     printf("%d\n", sizeof(arr));//6，整个数组的大小
//     printf("%d\n", sizeof(arr + 0));//4/8，第一个元素的地址
//     printf("%d\n", sizeof(*arr));//1，第一个元素的大小
//     printf("%d\n", sizeof(arr[1]));//1，第二个元素的大小
//     printf("%d\n", sizeof(&arr));//4/8，取出整个数组的地址
//     printf("%d\n", sizeof(&arr + 1));//4/8,越过整个数组的地址
//     printf("%d\n", sizeof(&arr[0] + 1));//4/8，第二个元素的地址

//     return 0;
// }

// int main()
// {
//     char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};

//     printf("%d\n", strlen(arr));         //随机值random numbers‘n’, because there is no character'\0'
//     printf("%d\n", strlen(arr + 0));     // random number'n', because you need to count from 'b'
//     printf("%d\n", strlen(*arr));        //字符'a'码值是97，是野指针，不能访问空间会报错
//     printf("%d\n", strlen(arr[1]));      //野指针
//     printf("%d\n", strlen(&arr));        //&arr取出整个数组的地址，传给strlen，读取char*类型。虽然传入两个类型是不一样的，但是读取都按照char*，所以=n
//     printf("%d\n", strlen(&arr + 1));    //n-6
//     printf("%d\n", strlen(&arr[0] + 1)); //n-1
//     return 0;
// }
// strlen是求字符串长度的，关注的是字符串中的\0，计算的是\0之前出现字符的个数
// strlen库函数，只针对字符串
// sizeof只关注占用内存空间的大小，不在乎内存中放什么
// sizeof是操作符
// int main()
// {
//     char arr[] = {"abcdef"};

// printf("%d\n", strlen(arr));         // 6 数的是'\0'之前的字符个数
// printf("%d\n", strlen(arr + 0));     // 6
// printf("%d\n", strlen(*arr));        // err
// printf("%d\n", strlen(arr[1]));      // err
// printf("%d\n", strlen(&arr));        // 6
// printf("%d\n", strlen(&arr + 1));    //随机值
// printf("%d\n", strlen(&arr[0] + 1)); // 5
// return 0;
// }

// int main()
// {
//     char arr[] = "abcdef";

//     printf("%d\n", sizeof(arr));//7, include '\0'
//     printf("%d\n", sizeof(arr+0));//4/8,arr此时代表首元素地址，地址大小就是4/8
//     printf("%d\n", sizeof(*arr));//1,a
//     printf("%d\n", sizeof(arr[1]));//1,b
//     printf("%d\n", sizeof(&arr));//4/8,整个数组的地址
//     printf("%d\n", sizeof(&arr+1));//4/8，跳过数组的地址
//     printf("%d\n", sizeof(&arr[0]+1));//4/8，b的地址
//     return 0;
// }

// int main()
// {
//     char arr[] = "abcdef";

//     printf("%d\n", sizeof(arr));         // 7, include '\0'
//     printf("%d\n", sizeof(arr + 0));     // 4/8,arr此时代表首元素地址，地址大小就是4/8
//     printf("%d\n", sizeof(*arr));        // 1,a
//     printf("%d\n", sizeof(arr[1]));      // 1,b
//     printf("%d\n", sizeof(&arr));        // 4/8,整个数组的地址
//     printf("%d\n", sizeof(&arr + 1));    // 4/8，跳过数组的地址
//     printf("%d\n", sizeof(&arr[0] + 1)); // 4/8，b的地址
//     return 0;
// }

// int main()
// {
//     char *p = "abcedf";                //指向a的地址
//     printf("%d\n", sizeof(p));         // 4/8
//     printf("%d\n", sizeof(p + 1));     // 4/8
//     printf("%d\n", sizeof(*p));        // 1
//     printf("%d\n", sizeof(p[0]));      // 1
//     printf("%d\n", sizeof(&p));        // 4/8，指向常量字符串的地址
//     printf("%d\n", sizeof(&p + 1));    // 4/8，指向常量字符串之后的地址
//     printf("%d\n", sizeof(&p[0] + 1)); // 4/8，指向b

//     printf("%d\n", strlen(p)); //6
//     printf("%d\n", strlen(p + 1));//5
//     printf("%d\n", strlen(*p));//*p --> a, strlen(a) = strlen(97), err
//     printf("%d\n", strlen(p[0]));//err
//     printf("%d\n", strlen(&p));//随机值
//     printf("%d\n", strlen(&p + 1));//随机值
//     printf("%d\n", strlen(&p[0] + 1));//5

//     return 0;
// }

// int main()
// {
//     int a[3][4] = {0};
//     printf("%d\n", sizeof(a));            // 48
//     printf("%d\n", sizeof(a[0][0]));      // 4
//     printf("%d\n", sizeof(a[0]));         // 16,a[0]单独放在括号内部，是代表a首元素地址，第一行的地址
//     printf("%d\n", sizeof(a[0] + 1));     // 4/8，a[0]不是单独放在内部，也没有取地址，是代表的首元素的地址 <=> &a[0][0]+1，第一行第二个元素的地址
//     printf("%d\n", sizeof(*(a[0] + 1)));  // 4
//     printf("%d\n", sizeof(a + 1));        // 4/8，第二行的地址
//     printf("%d\n", sizeof(*(a + 1)));     // 16
//     printf("%d\n", sizeof(&a[0] + 1));    // 4/8 ->第二行
//     printf("%d\n", sizeof(*(&a[0] + 1))); // 16，第二行
//     printf("%d\n", sizeof(*a));           // 16，数组名没单独放在sizeof内部，就是首元素的地址，就是第一行的地址，然后解引用为第一行
//     printf("%d\n", sizeof(a[3]));         // 16

//     return 0;
// }

//指针题目：
// 1.
// int main()
// {
//     int a[5] = {1, 2, 3, 4, 5};
//     int *ptr = (int *)(&a + 1);//&a是取出数组的地址，他的类型应该是int(*ptr)[5],强制类型转化只是改变了他的类型，并未改变它指向的位置。
//     printf("%d %d", *(a + 1), *(ptr - 1));//2 5
//     return 0;
// }

// 2
//  struct Test
//  {
//      int Num;
//      char *pcName;
//      short sDate;
//      char cha[2];
//      short sBa[4];
//  } *  p=(struct Test*)0x100000;//p是一个结构体指针，+1跳过一个结构体。
//假设p的值为0x100000.如下表达式的值分别为多少？
//已知结构体Test类型的变量大小为20个字节（X86）
//  int main()
//  {
//      printf("%p\n", p + 0x1);//0x100000 + 20 = 0xx100014
//      printf("%p\n", (unsigned long)p + 0x1);//整数加一就是加1，0x100000+1 = 0x100001
//      printf("%p\n", (unsigned int*)p + 0x1);//跳过一个整型的大小，就是加04 = 0x100004
//      return 0;
//  }

// int main()
// {//%x为打印十六进制的数值
//     int a[4] = {1, 2, 3, 4};
//     int *ptr1 = (int *)(&a + 1);
//     int *ptr2 = (int *)((int)a + 1);//a强制类型转化为int，就不是地址+1了，而是整数加一。
//     //a： 0x0012ff40
//     //a+1:0x0012ff44
//     //(int)a+1:0x0012ff41
//     // 低地址--------------->高地址（小端）
//     //01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//     //  |                                |
//     // ptr2: 00 00 00 02                ptr1[-1]
//     // 0x02 00 00 00                  0x00 00 00 04
//     //
//     printf("%x %x", ptr1[-1], *ptr2);//0x4,0x2000000
//     return 0;
// }

// int main()
// {
//     int a[3][2] = {(0, 1), (2, 3), (4, 5)};
//     //区别（）逗号表达式，和{{},{},{}};
//     //
//     int *p;
//     p = a[0];
//     printf("%d", p[0]);
//     //a[0][0]
//     return 0;
// }

// int main()
// {
//     int a[5][5];
//     int(*p)[4];//数组指针
//     p = a;//a此时代表首元素就是第一行的地址，但a ->int(*)[5], p ->int(*)[4]
//     printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//     //p[4][2] -> *(*(p+4)+2)
//     //两个指针相减，得到相差的元素个数
//     //-4 以%p打印,写出原反补，1111 1111 1111 1111 1111 1111 1111 1100
//     //以p打印，地址不需要原反补，直接打印ff ff ff fc
//     //%d,拿原码，-4
//     //
//     return 0;
// }

// int main()
// {
//     int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int *ptr1 = (int *)(&aa + 1);//10之后的地址
//     int *ptr2 = (int *)(*(aa + 1));//aa是首元素的地址，但是二维数组首元素是第一行的地址，+1为第二行第一个
//     printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10，5
//     return 0;
// }

//数组名的意义:
// 1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
// 2. &数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
// 3. 除此之外所有的数组名都表示首元素的地址。

// int main()
// {
//     char *a[] = {"work", "at", "alibaba"};
//     char **pa = a;
//     pa++;
//     printf("%s\n", *pa);//%s需要一个地址
//     return 0;
// }//要画图，三个char*元素的数组，是指针数组
//存放三个字符串的地址："work","at","alibaba"
// pa类型char**，放的是work的地址。pa++，放的是at的地址了。

// int main()
// {
//     char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
//     char **cp[] = {c + 3, c + 2, c + 1, c};
//     char ***cpp = cp;
//     printf("%s\n", **++cpp);//POINT
//     printf("%s\n", *--*++cpp + 3);//ER
//     printf("%s\n", *cpp[-2] + 3);//ST
//     printf("%s\n", cpp[-1][-1] + 1);//EW
//     return 0;
// }
// c[]指针数组，char*类型的四个字符地址"ENTER", "NEW", "POINT", "FIRST"
// cp存放的是四个char**类型的指针的地址，二级指针，分别是"FIRST", "POINT", "ENTER", "NEW"
// cpp存放的是cp中首字符的地址"FIRST"
//**++cpp，先++后使用，POINT，cpp->POINT
//*++cpp,cpp->ENTER,
//*--*++cpp,cpp->
//这个做法是错误的，应该真正的画图，然后看指向。
