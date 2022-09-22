#include <string.h>
#include <stdio.h>
#include <assert.h>
//一系列的字符串的函数
//必须进行深刻的了解，才能用的时候不出错
//
// 1.strlen
//专门用来求一个字符串的函数
// strlen计算或者返回\0之前的字符个数
//
// int main()
// {
//     char arr[] = "abcedf"; // abcedf\0
//     int len = strlen(arr);
//     printf("%d\n", len); // 6
//     //strlen计算或者返回\0之前的字符个数
//     char arr2[] = {'b', 'i', 't'};
//     int len2 = strlen(arr2);
//     printf("%d\n", len2);//随机值，代码也没有意义
//     return 0;
// }
// cplusplus.com --
// size_t strlen(const )
// int main()
// {
//     if(strlen("abc")-strlen("abcedf")>0)//可以直接比较strlen(arr1)>strlen(arr2)
//     {
//         printf(">\n");
//     }
//     else
//     {
//         printf("<\n");
//     }
//     return 0;
//     //结果>,因为size_t -> unsigned long类型，无符号的，不可能为负
// }
//模拟实现

//计数方法
//计数器方法
//指针减指针
//递归的方法

// size_t my_strlen(const char* str)
// {
//     size_t count = 0;
//     assert(str);
//     while(*str!='\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }
// int main()
// {
//     char arr[] = "abc";
//     size_t len = my_strlen(arr);
//     printf("%u\n", len);
//     return 0;
// }

// 2.strcpy
//字符串拷贝
// strcpy-->char*strcpy(char*des,char*source);
// copy the c string pointed by source into the array pointed by destination, including the terminating null character(and stopping at that point)//拷贝\0

// int main()
// {
//     char name[20] = "0";
//     //"zhangsan"放入char中
//     strcpy(name, "zhangsan");
//     printf("%s", name);
//     //不能直接赋值，数组名是地址，地址是一个常量值，不能被赋值。
//     //拷贝到\0就自动停止
//     //必须注意：
//     //1.原数据source必须有\0才能被cpy
//     //2.目标空间必须足够大
//     //3.目标空间必须可编辑
//     return 0;
// }
//返回目标空间的起始地址
// char* my_strcpy(char*dest,const char* src)
// {
//     assert(dest && src);
//     char *ret = dest;
//     while (*dest++ = *src++)
//         ;
//     return ret;
// }
// int main()
// {
//     char arr1[] = "abcedf";
//     char arr2[20] = {0};
//     my_strcpy(arr2, arr1);
//     printf("%s\n", arr2);
//     return 0;
// }

//字符串追加
// 3.strcat
//返回目标空间的起始地址
//注意的问题：
// 1.目标空间足够大
// 2.目标空间可修改
// 3.原字符串必须含'\0'

// char* my_strcat(char*dest,const char* src)
// {
//     assert(src && dest);
//     char *ret = dest;
//     while (*dest++)
//     {
//         ;
//     }
//     while(*dest++ = *src++)
//     {
//         ;
//     }
// }
// int main()
// {
//     char arr1[20]="hello ";
//     my_strcat(arr1, "world");
//     printf("%s\n", arr1);
//     return 0;
// }
//自己给自己追加，会陷入死循环。因为这个'\0'会被后面的替代，就导致没有'\0'了。

// int my_strcmp(const char* arr1,const char* arr2)
// {
//     assert(arr1 && arr2);
//     while (*arr1++ == *arr2++)
//     {
//         if(*arr1 =='\0')
//         return 0;
//     }
//     return (int)(*arr1 - *arr2);
// }
// int main()
// {
//     char arr1[20] = "zhangsan";
//     char arr2[] = "zhangsanfeng";
//     //比较两个字符串是否相等
//     //arr1数组名，数组名是数组首元素的地址
//     //arr2是数组名。
//     //如果直接使用arr1==arr2，这是在比较两个字符串的地址，而不是比较的两个字符串的内容
//     //比较两个字符串是否相等，需要用strcmp
//     //strcmp不是比较大小，而是比较内容
//     if(strcmp(arr1,arr2)==0)
//     {
//         printf("=\n");
//     }
//     return 0;
// }

// strcmp,strcpy,strcat:长度不受限制的字符串函数，但是这样可能会造成安全隐患。
//如果想要变成长度受限的函数:strncpy,strncmp,strncat，多一个参数size_t num,要比较/拷贝/追加多少个字符
// strncat,num为几就从dest的\0位置处开始追加，但是在最后会补\0
//  int main()
//  {
//      char arr1[20] = "abcdef";
//      char arr2[] = "hello bit";
//      strncpy(arr1, arr2, 5);
//      printf("%s\n", arr1);
//      return 0;
//  }
//以后使用，尽量使用带n的函数，这样会更严谨。

// 4.strstr
//查找子串的函数
//返回NULL或者str1找到str2的地址char*
//  char* my_strstr(const char* str1,const char* str2)
//  {
//      assert(str1 && str2);
//      const char *s1 = str1;
//      const char *s2 = str2;
//      const char *p = str1;
//      while(*p)
//      {
//          s1 = p;
//          s2 = str2;
//          while(*s1++ ==*s2++ && *s1 != '\0'&& *s2!='\0')
//          {
//              ;
//          }
//          if(*s2 =='\0')
//          {
//              return (char*)p;
//          }
//          p++;
//      }
//      return NULL;
//  }
//  int main()
//  {
//      char email[] = "zpw@bitjiuyeke.com";
//      char substr[] = "bitjiuyeke";
//      char *ret = my_strstr(email, substr);
//      if(ret ==NULL)
//      {
//          printf("substr nonexist\n");
//      }
//      else {
//          printf("%s\n", ret);
//      }
//      return 0;
//  }

//但是上述算法查找str并不高
//可以采用KMP算法，高效，但是实现难度大

// 5.strtok
//简单用来切割字符串
//
//  songcy1205@gmail.com
//
//  int main()
//  {
//      const char *sep = "@.";
//      char email[] = "songcy1205@gmail.com";
//      //strtok(email, sep);//strtok会改变原串，所以可以先用strcpy去复制一个相同的串
//      char sp[30] = {0};
//      strcpy(sp, email);
//      // char *ret = strtok(sp, sep);//如果找到了，指向起始地址
//      // printf("%s\n", ret);
//      // ret = strtok(NULL, sep);//然后第一个参数改为NULL，会指向第一个分隔符后的地址
//      // printf("%s\n", ret);
//      // ret = strtok(NULL, sep);
//      // printf("%s\n", ret);
//      // return 0;
//      //这么写是可以的，但是极其麻烦，可以采用for循环：
//      char *ret = NULL;
//      for (ret = strtok(sp, sep); ret != NULL;strtok(NULL,sep))
//      {
//          printf("%s\n", ret);
//      }
//      return 0;
//  }
//为什么传入空指针NULL，可以继续的进行查找分割呢？
//因为strtok有记忆功能
//

// 6.strerror
//返回错误码所对应的错误信息
// c语言的库函数在执行失败的时候，都会设置错误码
// 0 1 2 3 4 5 6 7 8
//
//  char * strerror()
#include <errno.h>
// int main()
// {
//     // printf("%s\n", strerror(0));//0: no error
//     // errno - c语言设置的一个全局的错误码存放的变量,需要使用errno.h头文件
//     FILE* pf = fopen("test.txt", "r");//打开文件，r只读
//     if(pf ==NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 1;
//     }
//     else{
//         ;
//     }
//     return 0;
// }

//字符分类函数：需要ctype.h头文件
//详情见课件，进阶3 字符分类函数
//如 isspace，是空白字符返回1，否则返回0
#include <ctype.h>
// int main()
// {
//     int a =isspace(' ');
//     printf("%d\n", a);
//     return 0;
// }
// iscntrl,任何控制字符
// isspace,空白字符，包括空格，换页\f,换行\n,回车\r,制表符\t,垂直制表符\v
// isdigit,十进制数字0-9
// isxdigit,十六进制数字，包括所有的十进制数字，大小写字母
// islower,小写字母
// isupper,大写字母
// isalpha,大小写字母
// isalnum,字母或者数字
// ispunct,标点符号，任何不属于数字或者字母的图形字符（可打印）
// isgraph,任何图形字符
// isprint,任何可以打印的字符，包括图形字符和空白字符
//

//字符转换函数
// tolower，传入大写字母，转换为小写字母
// toupper，传入小写字母，转换为大写字母