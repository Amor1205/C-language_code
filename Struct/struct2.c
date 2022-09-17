#include <stdio.h>
// 3.枚举
//顾名思义就是一一列举
//把可能的取值一一列举
//
// 3.1枚举类型的定义
//
// enum Day
// {
//     Mon = 1,
//     Tues,
//     Wed,
//     Thur,
//     Fri,
//     Sat,
//     Sun
// };
// struct Stu
// {
//     int a;
//     char c;
// };
// //在枚举里面，用逗号
// //在结构体里面用分号
// int main()
// {
//     enum Day d = Fri;
//     return 0;
// }
// enum Day就是枚举类型，{}中的内容是枚举类型的可能去值，也叫枚举常量
//这些可能取值都是有值的，默认从0开始，一次递增1，当然在定义的时候也可以赋初值

// 3.2枚举的好处
//  1.增加代码的可读性和可维护性
//  2.和#define定义的标识符比较枚举有类型检查，更加严谨(c++更明显)
//  3.防止了命名污染（封装）
//  4.便于调试
//  5.使用方便，一次可以定义多个常量

// 4.联合(共用体)
// 4.1 联合类型的定义
//联合也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员，特征是这些成员共用同一块空间，所以联合也叫共用体。
// union Un
// {
//     int a;
//     char c;
// };
// struct St
// {
//     int a;
//     char c;
// };
// int main()
// {
//     union Un u;
//     printf("%d\n", sizeof(u));//4
//     printf("%p\n", &u);
//     printf("%p\n", &(u.a));
//     printf("%p\n", &(u.c));
//     //四个字节由a和c共用
//     return 0;
// }

// 4.2联合类型的特点
//内存共用，代表地址相同，修改一方的地址，同时也修改联合的其他的地址，始终保持相同
//
//判断大小端
//  int check_sys()
//  {
//      int a = 1;
//      return (int)(*(char *)&a);
//  }
//  int check_sys2(void)
//  {
//      union Un
//      {
//          char c;
//          int i;
//      }u;
//      u.i = 1;
//      return (int)u.c;//返回0大端，返回1小端
//  }
//  int main()
//  {
//      //int a = 1; // 0x00 00 00 01
//      //低 --> 高
//      //01 00 00 00 -小端
//      //00 00 00 01 -大端
//      int ret = check_sys2();
//      if(ret ==1)
//          printf("Small-end storage\n");
//      else
//          printf("Big-end storage\n");
//          return 0;
//  }

// 4.3联合大小的计算
//联合的大小至少是最大成员的大小；
//当最大成员大小不是最大对齐数的整数倍时，就要对齐到最大对齐数的整数倍
//
//  union Un
//  {
//      char arr[5];//5
//      int i;//4
//  };
//  int main()
//  {
//      printf("%d\n", sizeof(union Un));//8, 应该为4的倍数，也存在着对齐、浪费
//      return 0;
//  }
// example2
//  union Un
//  {
//      short arr[7];
//      int i;
//  };
//  int main()
//  {
//      printf("%d\n", sizeof(union Un));//16, 2*7=14 -> 16
//      return 0;
//  }