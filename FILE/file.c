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
// int main()
// {
//     struct S s = {0};
//     // open the file
//     FILE *pf = fopen("text.txt", "rb");
//     if (pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     // read
//     fread(&s,sizeof(struct S),1,pf));
//     printf("%s %d %lf\n", s.name, s.age, s.d);

//     return 0;
// }

// 5.文件的随机读写
// 5.1 fseek
// int fseek(FILE* stream, long offset,int origin);//流--偏移量--
// int origin 有三个参数： SEEK_CUR(current文件指针当前的位置),SEEK_END(文件末尾的位置),SEEK_SET(文件开始的位置)

// fseek+fgetc = 随机读
//  int main()
//  {
//      //open and check the file
//      FILE* pf = fopen("text.txt", "r");
//      if(pf ==NULL)
//      {
//          perror("fopen");
//          return 1;
//      }
//      //write randomly
//      //read randomly
//      int ch = fgetc(pf);
//      printf("%c\n", ch);

//     ch = fgetc(pf);
//     printf("%c\n", ch);

//     fseek(pf, 2, SEEK_SET);
//     ch = fgetc(pf);
//     printf("%c\n", ch);

//     fseek(pf, 2, SEEK_CUR);
//     ch = fgetc(pf);
//     printf("%c\n", ch);

//     fseek(pf, -2, SEEK_END);
//     ch = fgetc(pf);
//     printf("%c\n", ch);

//     // close the file
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// fseek+fputc = 随机写
//  int main()
//  {
//      FILE *pf = fopen("text.txt", "w");
//      if(pf==NULL)
//      {
//          perror("fopen");
//          return 1;
//      }
//      //write
//      fputc('a', pf);
//      fputc('b', pf);
//      fputc('c', pf);
//      fputc('d', pf);
//      fputc('e', pf);
//      fputc('f', pf);
//      fseek(pf, -3, SEEK_CUR);
//      fputc('w', pf);
//      long t = ftell(pf);
//      printf("%ld", t);
//      // d->w
//      //  close
//      fclose(pf);
//      pf = NULL;
//      return 0;
//  }

// 5.2ftell
// long ftell(FILE* stream)
//用来显示当前文件流的偏移量，如上所示

// 5.3 rewind
//  void rewind(FILE* stream)
//让文件指针的位置回到文件的起始位置

//文本文件和二进制文件(.obj)
//根据数据的组织形式，数据文件分为文本文件和二进制文件
//数据在内存中以二进制的形式储存，如果不加转换的输出到外存，就是二进制文件。
//如果要求在外存上以ASCII码值的形式存储，则需要在存储前转化。以ASCII字符的形式存储的文件就是文本文件。
//一个数据在内存中是如何存储的呢？
//字符一律以ASCII形式存储。数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储。

//假设有一个整数10000，如果以ASCII码值的形式，把每位都当作一个字符。总共五个字符，即五个字节。
//如果以二进制存储，只占4个字节（一个int）
//
//测试代码
// int main()
// {
//     int a = 10000;
//     FILE *pf = fopen("text.txt", "wb");
//     if(pf==NULL)
//     {
//         return 1;
//     }
//     fwrite(&a, 4, 1, pf);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 7.文件读取结束的判定
// 7.1被错误使用的feof
//牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件的是否结束
// feof是 应用于当文件读取结束的时候，判断是读取失败结束还是遇到文件尾结束的函数。
//
//文本文件读取是否结束，判断返回值是否为EOF(fgetc)或者NULL(fgets)
//判断fgetc返回值是否为EOF
//判断fgets返回值是否为NULL

//二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
//例如：
// fread判断返回值是否小于实际要读的个数

//正确使用的例子
// text:
// int main()
// {
//     int c;
//     FILE *pf = fopen("text.txt", "r");
//     if(!pf)
//     {
//         perror("fopen");
//         return 1;
//     }
//     while((c = fgetc(pf))!=EOF)
//     {
//         putchar(c);
//     }
//     if(ferror(pf))//判断是否是遇到错误而结束的
//         puts("I/O error when reading");
//     else if (feof(pf))//判断是否是到文件末尾而结束的
//         puts("End of file reached successfully");
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 8.文件缓冲区
//从内存像磁盘输出数据会首先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。
//如果从磁盘像计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），在从缓冲区逐个的将数据送到程序数据区（程序变量等）。
//缓冲区的大小根据C编译系统决定的。

//              ----> 输出缓冲区  ------>
// 程序数据区                               硬盘
//              <---- 输入缓冲区  <------

//简单测试
// int main()
// {
//     FILE *pf = fopen("text.txt", "w");
//     fputs("abcdef", pf);
//     printf("SLEEP for 20 sec, already fputs but no content\n");
//     Sleep(20000);

//     printf("manually flush buffer\n");//use "fflush"
//     fflush(pf);//when flushing buffer, the data has been written in the file
//     printf("SLEEP again for 20 sec,and then open the file, find that there are content in the file\n");
//     Sleep(20000);

//     fclose(pf);
//     //when closing the file, the buffer will also be cleaned
//     pf = NULL;
//     return 0;
// }
