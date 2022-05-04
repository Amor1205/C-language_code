#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//typedef 可以把复杂的简化，类型重命名。起个新名字。
//typedef unsigned int uint;
//
//int main()
//{
//	unsigned int num = 0;
//	uint num2 = 1;
//	return 0;
//}
//

//static 修饰：局部变量 全局变量 函数、
// 例子1：修饰局部变量
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test();
//		i++;           //循环十次。
//	}
//	return 0;
//}           

//例子2 修饰全局变量

//extern int a //声明外部符号（外面文件的变量）



//#define num 100
//int main()
//{
//	printf("%d", num);
//	return 0;
//}


//add函数
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(a, b);
//	printf("%d", c);
//	return 0;
//}

//#define add(x,y) x+y
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(a, b);
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//& 是取地址操作符
//	//printf("%p", &a);
//	int* p = &a;
//	//p 就是指针变量 
//	*p = 20; //*p 解引用操作符，意思就是通过p中存放的地址找到p所指向的对象，*p就是p指向的对象。
//	printf("%d\n", a);
//	return 0;
//

//int main()
//{
//	//不管是什么类型的指针，都是在创建指针变量
//	//指针变量都是用来存放地址的。
//	//指针变量的大小取决于一个地址存放的时候需要多大的空间
//	//32位机器上 32bit位 4byte 指针变量大小是四个字节
//	//64位机器上 8byte
//	// x86就是32位平台
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(double*));
//	printf("%d\n", sizeof(short*));
//
//	return 0;
//}

//结构体

//学生
struct Stu
{
	char name[20];
	int age;
	char sex[10];
	char tel[12];

};

void print(struct Stu* ps)
{
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tel);

	//操作符 ->
	//结构体指针变量 -> 成员名

	printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tel);
}
int main()
{
	struct Stu a = { "zhangsan", 20 ,"male" , "1232132333" };

	//printf("%s %d %s %s", a.name, a.age, a.sex, a.tel);
	print(&a);
	return 0;
}
