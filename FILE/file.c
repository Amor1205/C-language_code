#include <stdlib.h>
#include <stdio.h>
//
//文件
//硬盘上的文件就是文件
//但是在程序设计中，我们一般谈的文件有两种，程序文件和数据文件
// 2.1程序文件
//包括源程序文件（.c），目标文件（windows环境后缀为obj），可执行程序（windows环境后缀为.exe）
// 2.2数据文件
//文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件

//主要讨论数据文件
//

//文件名
//一个文件要有一个唯一的文件标识
//文件名包括： 文件路径+文件名主干+文件后缀
//如c:/code/test.txt
//方便起见，文件标识常被称为文件名

// 3.文件的打开和关闭
// 3.1文件指针
//缓冲文件系统中，关键的概念是“文件类型指针”，简称文件指针
//每个被使用的文件，都在内存中开辟了一个相应的文件信息区，用来存放文件相关信息。这种信息保存在内存中的FILE文件中。
//可以创建FILE*的指针变量
// FILE *pf; //文件指针变量
// pf指向FILE类型数据的指针变量

// 3.2文件的打开和关闭
//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件
//
//先介绍fopen函数
// FILE* fopen(const char* filename, const char* mode)
// return FILE*，是打开文件时会创建一个文件信息区，然后返回这个文件信息区的起始地址。
//打开文件失败会返回空指针
// mode->打开方式，“r”读，“w”写，“a”追加-像文本文件尾田家数据，rb只读-为了输入数据打开一个二进制文件，wb只写-为了输出数据打开一个二进制文件，ab追加-二进制追加，......
//  int main()
//  {
//      //打开文件
//      FILE *pf = fopen("D:\\code\\test.c", "r");//可以指定路径，注意需要转译
//      if(pf == NULL)
//      {
//          perror("fopen");
//          return 1;
//      }
//      //操作文件

//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

//注意w打开时，如果有文件，会先销毁，重新进行编写。
// int main()
// {
//     FILE* pf = fopen("/users/amor/code/text.txt", "w");
//     if(pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     //写文件-- 输出
//     //int fputc(int c,file* stream)
//     for (char ch = 'a'; ch <= 'z';ch++)
//     {
//         fputc(ch, pf);
//         fputc(' ', pf);
//     }
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }

//读文件
// int main()
// {
//     FILE *pf = fopen("/users/amor/code/text.txt", "r");
//     if (pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     //读文件-- 输入操作 （读到程序里区）
//     //字符输入函数 int fgetc(file* stream)
//     //return the character read as an int or return EOF
//     int ch = 0;
//     while((ch = fgetc(pf))!= EOF)
//     {
//         printf("%c ", ch);
//     }
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }

//流 --
// 外部设备：键盘、屏幕、u盘，硬盘、网卡.....
//操作不同的外部设备的操作各不相同
// 使用流，在外部设备的上层封装一层流，程序员只需要负责写入流和读取流即可。
//
//流 又分为：文件流(FILE)/标准输入流(stdin)/标准输出流(stdout)/标准错误流(stderr)等等
//只要一个c程序运行起来，后三个流都是默认打开的。stdin - 键盘， stdout、stderr - 屏幕，这三个流的类型都是FILE*
//我们写数据写到流里面，并不关心流如何流向外部设备。
//

// int main()
// {
//     FILE *pf = fopen("/users/amor/code/text.txt", "w");
//     if(pf ==NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     //写文件 --写一行
//     //
//     fputs("dkjadjwjdk", pf);
//     fputs("xxxxxxxxxx", pf);
//     fputs("dkjadjwjdk", pf);

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

//读文件
// int main()
// {
//     char arr[256] = {0};
//     FILE *pf = fopen("/users/amor/code/text.txt", "r");
//     if (pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     //读文件 --一次读一行
//     // char* fgets(char* string,int n,FILE* stream);
//     // string -> Storage location for data
//     // n -> Maximum number of characters to read(最多读n-1个，留一个给'\0')
//     // stream -> Pointer to FILE structure
//     // fgets(arr, 255, pf); //读第一行
//     // printf("%s", arr);
//     // fgets(arr, 255, pf); //读第二行
//     // printf("%s", arr);
//     //但是一般情况下不知道文件有多少行,使用如下代码
//     while(fgets(arr,256,pf) != NULL)
//     {
//         printf("%s", arr);
//     }

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

//格式化的输入和输出函数 fscanf / fprintf
// 1.fprintf -- 针对所有输出流的格式化输出函数
// struct S
// {
//     char name[20];
//     int age;
//     double d;
// };
// int main()
// {
//     struct S s = {"zhangsan", 20, 95.5};
//     //open the file
//     FILE* pf = fopen("text.txt", "w");
//     if(pf==NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     //modify the file
//     //fprintf(FLIE* stream,const char* format [,argument]...)
//     fprintf(pf, "%s %d %lf", s.name, s.age, s.d);

//     //close the file
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 2.fscanf -- 针对所有输出流的格式化输出函数
//  struct S
//  {
//      char name[20];
//      int age;
//      double d;
//  };
//  int main()
//  {
//      struct S s = {0};
//      FILE *pf = fopen("text.txt", "r");
//      if(pf==NULL)
//      {
//          perror("fopen");
//          return 1;
//      }
//      //读取
//      fscanf(pf, "%s %d %lf", s.name, &(s.age), &(s.d));
//      return 0;
//  }

// sprintf  -- 把格式化的数据转化成为一个字符串
// int sprintf(char* buffer, const char* format [,argument]...);
// sscanf -- 把字符串转化成格式化数据
// struct S
// {
//     char name[20];
//     int age;
//     double d;
// };
// int main()
// {
//     char buf[256] = {0};
//     struct S s = {"zhangsan", 20, 95.5};
//     struct S tmp = {0};
//     //读取
//     sprintf(buf, "%s %d %lf", s.name, s.age, s.d);
//     printf("%s\n", buf);
//     //从buf字符串中提取结构体数据
//     sscanf(buf, "%s %d %1f", tmp.name, &(tmp.age), &(tmp.d));
//     printf("%s %d %lf", tmp.name, tmp.age, tmp.d);

//     return 0;
// }

// scanf - 格式化的输入函数
// printf - 格式化的输出函数

// fscanf
// fprintf

// sscanf
// sprintf

//二进制输入 fread
//二进制输出 fwrite  -- 我们下达指令写东西给文件，叫输出
// size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream)
struct S
{
    char name[20];
    int age;
    double d;
};
// int main()
// {
//     struct S s = {"zhangsan", 20, 96.5};
//     //写文件-用二进制的方式写
//     FILE *pf = fopen("text.txt", "wb");
//     if(pf ==NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     //二进制的方式写入
//     //
//     fwrite(&s, sizeof(struct S), 1, pf);
//     //close the file
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }
//二进制方式读文件
// size_t fread (void* buffer, size_t size,size_t count,FILE* stream);
int main()
{
    struct S s = {0};
    // open the file
    FILE *pf = fopen("text.txt", "rb");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    // read
    fread(&s,sizeof(struct S),1,pf));
    printf("%s %d %lf\n", s.name, s.age, s.d);

    return 0;
}