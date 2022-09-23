// program environment

#include <stdlib.h>
#include <stdio.h>
// 1.程序的翻译环境和执行环境
//在ANSI C的任何一种实现中，存在两个不同的环境。
//一个是翻译环境，在这个环境中源代码被转换为可执行的机器指令(test.c -> test.exe)
//一个是执行环境，他用于实际执行代码。(运行test.exe的环境)

// 1.1翻译环境
//  不同源文件经过编译器(cl.exe)处理，生成目标文件(.obj)
//  多个目标文件加上链接库 经过链接器(link.exe)的处理，生成可执行程序(.exe)

//编译的过程：预编译-编译-汇编
//
// linux环境下，头文件放在/user/include里

//预处理/预编译：
//预编译会生成test.i文件(test.c -> test.i)
//会进行包含头文件、#define定义符号的替换、注释的删除
//#include -- 预处理指令，#define -- 预处理指令，
//都是文本操作

//编译：
// test.i ->test.s
//都把C语言代码变成汇编代码了
//语法分析、词法分析、语义分析、符号汇总

//计算机《编译原理》会教

//符号汇总：在符号汇总前，每个文件都是独立的，最后在符号汇总前， 只会汇总全局变量，如main，
//
//汇编：
// test.s -> test.o
// windows 目标文件（.obj）,linux(.o)
//作用1：把汇编指令转化为二进制指令
//作用2：形成符号表
// linux环境下 test.o/可执行程序的格式是： elf ，可以用readelf命令去查看.o里面的符号表
//
//如果只是声明函数但是不定义，会在链接期间报错。是因为在符号表合并的时候会找不到函数符号的地址。
//名字写错也会导致符号不同，从而导致在链接期间报错。
//《程序员的自我修养》

// 2.3运行环境
//程序执行的过程
// 1.程序必须载入内存中。在有操作系统的环境中：一般这个由操作系统完成。在独立的环境中，程序的载入必须由手工完成，也可能是通过可执行代码置入只读内存来完成
// 2.程序的执行便开始。接着便调用main()函数。
// 3.开始执行程序代码。这个时候程序将使用一个运行时堆栈(stack)，存储函数的局部变量和返回地址。程序同时也可以使用静态内存(static)，存储于静态内存中的变量在程序的整个执行过程一直保留他们的值。
// 4.终止程序。正常终止main函数；也有可能是意外终止。

// 3预处理详解
// 3.1预定义符号
// __FILE__ //进行编译的源文件
// __LINE__ //文件当前的行号
// __DATE__ //文件被编译的日期
// __TIME__ //文件被编译的时间
// __func__ //当前所处的函数名
// __STDC__ //如果编译器遵循ANSI C，其值应为1.否则未定义。
//这些东西都可以被打印出来
//
//我们可以把这些东西写进文件里，当作工作日志
//例子
// int main()
// {
//     int i = 0;
//     FILE *pf = fopen("log.txt", "a");
//     if(pf ==NULL )
//     {
//         perror("fopen");
//         return 1;
//     }
//     for (i = 0; i < 10;i++)
//     {
//         fprintf(pf, "name:%s file:%s line:%d date:%s time:%s i=%d", __func__, __FILE__, __LINE__, __DATE__, __TIME__, i);
//     }
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }

//#define定义标识符
//#define定义宏

// 3.1. 定义标识符
// #define MAX 100
// #define STR "abcdefg"
// int main()
// {
//     int max = MAX;
//     char *str = STR;

//     return 0;
// }
//在预处理阶段直接把后面的这种标识符替换掉。
//在预处理之后直接得到值
//#define后面不要加分号
//如果后面有分号，就会变成int max = 100;;

// 3.2 定义宏
//#define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏(macro) 或定义宏 (define macro)
//宏的申明方式
//#define name(parament-list) stuff
//其中parament-list是参数列表，符号表
//参数左括号必须与name靠在一起

// #define MAX(x,y) (x>y?x:y)

// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = MAX(a, b);
//     //预处理后为
//     // int c = (a>b?a:b);
//     printf("%d\n", c);
//     return 0;
// }

// #define SQUARE(x) x*x
// int main()
// {
//     int a = 10;
//     int r = SQUARE(a+1);
//     //int r = a+1 * a+1
//     //10 + 10 + 1 = 21
//     printf("%d\n", r);
//     return 0;
// }
// 宏是先把表达式替换过去，然后再进行计算
// 在写宏的时候不要吝啬括号
// 要先规定好再进行计算
// 最外层加一层括号，然后每个参数都要加括号

// 3.3 #define定义规则
//  在程序中扩展#define定义符号和宏时，需要设计几个步骤。
//  1.在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，他们首先被替换。
//  2.替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值所替换。
//  3.最后，在此对结果文件进行扫描，看看他们是否包含任何由#define定义的符号。如果是，就重复上述处理过程。

//注意：
// 1. 宏参数和#define定义中可以出现其他#define定义的符号。但是对于宏，不能出现递归。
// 2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。

//#和##
//如何把#插入到字符串中？

// int main()
// {
//     int a = 10;
//     printf("the value of a is %d\n", a);
//     int b = 20;
//     printf("the value of b is %d\n", b);
//     //可以封装函数吗？
//     return 0;
// }

// void print(int n)
// {
//     printf("the value of n is %d\n", n);
// }
// //发现无论如何都得打印出来n
// #define PRINT(n) printf("the value of "#n """ is %d\n",n)
// int main()
// {
//     int a = 10;
//     // printf("the value of a is %d\n", a);
//     int b = 20;
//     // printf("the value of b is %d\n", b);
//     //可以封装函数吗？
//     PRINT(a);
//     PRINT(b);
//     return 0;
// }
// #define PRINT(N, format) printf("the value of "#N" is "format"\n", N)
// int main()
// {
//     int a = 20;
//     double pi = 3.14159;
//     PRINT(a,"%d");
//     PRINT(pi,"%lf");
//     return 0;
// }

//"#N" 可以不替换直接把参数传递过去，可以用于名字的打印
//
// ##
// 可以把位于他两边的符号合成一个符号。
// 它允许宏定义从分离的文本片段创建标识符
//
//
// #define CAT(name, num) name##num//##把name和num合并起来
// int main()
// {
//     int class1 = 1;
//     printf("%d\n", CAT(class, 1));
// }

//两个代码非常诡异，但是遇到要知道

// 3.2.5 带副作用的宏参数
//  当宏参数在红的定义中出现超过一次的时候，如果参数带有副作用，那么你在使用这个宏的时候可能就会出现危险，导致不可预测的后果，
//副作用就是指表达式求值的时候出现的永久性效果。
//例如：
//  x+1 不带副作用 而x++带副作用
//
//

// #define MAX(x,y) ((x)>(y)?(x):(y))
// int main()
// {
//     int a = 5;
//     int b = 8;
//     int c = MAX(a++, b++);//10
//     //(a++)>(b++)?(a++):(b++)
//     //(5)>(8)? --> (9) c = 9  b = 10 , a = 6
//     printf("%d\n", c);
//     printf("%d\n", a);
//     printf("%d\b", b);
//     return 0;
// }

//宏常常用于执行比较简单的运算，比如两者之间找最大
//为什么不用函数呢？

//原因：
// 1.用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。 所以宏比函数在程序的规模和速度方面更胜一筹
// 函数要调用、计算、返回。 宏只有计算
// 2.更重要的是：函数的参数必须声明为特定的类型
//所以函数只能在类型合适的表达式上面用。反之宏可以适用于整型、长整形、浮点型等可以用于>来比较的类型。 宏是类型无关的。

//宏的缺点：
// 1.每次使用宏时，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
// 2.宏无法调试和递归
// 3.宏由于类型无关，也就不够严谨
// 4.宏可能会带来优先级问题。导致程容易出现错误。
#include <stdlib.h>
//只能宏能做的事情：
//宏定义里面可以出现类型，但是函数不行
// #define MALLOC(num, type) (type *)malloc(num * sizeof(type))
// int main()
// {
//     int *p = (int *)malloc(10 * sizeof(int));
//     int *p2 = MALLOC(10, int);
//     return 0;
// }

//宏和函数的区别：很多，可以见课件
//内联函数 - C99 inline  结合函数的优点和宏的优点
//

// 3.2.7 命名约定
//一般宏名全部大写，函数不要全大写
//
//#undef 可以取消掉
//
//命令行定义
//许多c的编译器提供一种能力，允许在命令行中定义符号。用于启动编译过程
//例如：当我们根据同一个源文件要编译出不同的一个程序的不同版本时，这个特性有点用处。(假定某个程序中声明了一个某个长度的数组，如果机器内存有限，我们需要一个很小的数组，但是另外一个机器内存大一些，我们需要一个数组能够大一些。)

// 3.5 条件编译
//在一编译一个程序的时候我们如果要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件编译指令
//比如说：
//调试型的代码，删除可惜，保留又碍事，所以我们可以选择性的编译。

// int main()
// {
//     int arr[10] = {0};
//     for (int i = 0; i < 10;i++)
//     {
//         arr[i] = i;
//         #if 1
//         printf("%d\n", arr[i]);
//         #endif
//     }
//         return 0;
// }

//常见的条件编译指令
// 1. #if 常量表达式
//   #endif （常量表达式由预处理器求值）
// 2. 多分支条件编译
//   #if 常量表达式
//   #elif 常量表达式
//   #else
//   #endif
// #define NUM 1
// int main()
// {
// #if NUM == 2
//     printf("hehe\n");
// #elif NUM == 1
//     printf("heihei\n");
// #else
//     printf("gaga\n");
// #endif
//     return 0;
// }

// 3.判断是否被定义
//#if defined(macro)  -- #endif
//#ifdef  -- #endif

//判断是否未定义
//#if !defined(macro)  -- #endif
//#ifndef -- #endif
// #define MAX 1
// int main()
// {
// // #if defined(MAX) //写法1
// //     printf("hehe\n");
// //写法2如下
// #ifdef MAX
//     printf("hehe\n");
// #endif
//     return 0;
// }
//只要定义就可以，不在乎定义的值是什么

// #if defined(OS_UNTX)
//     #ifdef OPTION1
//     unix_version_option1();
//     #endif
//     #ifdef OPTION2
//     unix_version_option2();
//     #endif
// #elif defined(OS_MSDOS)
//     #ifdef OPTION2
//     msdos_version_option2();
//     #endif
// #endif

// 3.6 文件包含
//#include<stdio.h> ： <>指的是直接去查找标准库头文件
//#include"test.h" 查找本地文件，双引号指的是：
//首先去源文件所在目录下去查找test.h文件。如果没找到，编译器就像查找库函数头文件一样在标准位置查找头文件
//如果找不到就提示编译错误
// LINUX环境下标准头文件的目录在/usr/include
//不同的环境有不同的标准头文件目录
//
//尽量不要重复包含，
//因为包含头文件会把头文件的代码拷贝进源文件。
//包含一次就会拷贝一次
//所以在自己编写的头文件内部使用（1）：
#pragma once
//也可以使用（2）：
#ifndef __TEST_H__ //(一般使用的是头文件的名称)
#define __TEST_H__
// CODE IN HEAD FILE
#endif
// ---> 防止头文件的重复引用

// 4.其他的预处理指令
//预处理阶段会处理很多的预处理指令
//如 #include #define\#if \#endif \ #ifndef \ #elif \ #else \ #pragma \
//每个预处理指令又有各自的作用
//#pragma comment()
//#pragma once
//#pragma pack()
//  《C语言深度解剖》
