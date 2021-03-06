#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//算术操作符
// + - * / %
//    整型的除法 1/2 --> 0
//    浮点型的除法 1.0 / 2 --> 0.5 
// 要实现浮点型的除法，需要操作数里面只要收一个为浮点型
// % 取模操作符 ：计算的的整除后的余数，操作数必须为整数


//移位操作符
//  <<左移操作符
//  >>右移操作符
//  只针对整数
// 如

//int main()
//{
//int a = 7;
//int b = a << 1;
//printf("%d\n", a);//7   111   
//printf("%d\n", b);//14   1110  
//}

// 移动的是二进制
// 整数的二进制表示有三种
//原码
//反码
//补码
//正的整数的原码、反码、补码相同
//负的整数的原反补需要计算

//如 7 ： 
//原码---> 0000 0000 0000 0000 0000 0000 0000 0111
//反码---> 0000 0000 0000 0000 0000 0000 0000 0111
//补码---> 0000 0000 0000 0000 0000 0000 0000 0111
//- 7 ：
//原码---> 1000 0000 0000 0000 0000 0000 0000 0111
//反码---> 1111 1111 1111 1111 1111 1111 1111 1000（原码符号位不变，其他位按位取反）
//补码---> 1111 1111 1111 1111 1111 1111 1111 1001（反码+1为补码）
//补码-1取反得到反码
// 
//整数在内存中存的是补码
// 所以看：
//int main()
//{
//int a = 7;
//int b = a << 1;
//printf("%d\n", a);//7   111   
//printf("%d\n", b);//14   1110  
//}
//a  内存中 0000 0000 0000 0000 0000 0000 0000 0111
//b  内存中a向左移动一位 左移操作，左边丢弃，右边补0
//b  内存中 0000 0000 0000 0000 0000 0000 0000 1110   （14）
// a自身不变，b复制了a的补码再做操作。

//b = -7 << 1， a = -7
//a  1111 1111 1111 1111 1111 1111 1111 1001
//b  1111 1111 1111 1111 1111 1111 1111 0010（补码）
//b  1111 1111 1111 1111 1111 1111 1111 0001（反码）
//b  1000 0000 0000 0000 0000 0000 0000 1110（原码） -14


//左移1 乘2

//右移操作符
// 算数移位:右边丢弃，左边补原符号位
// 逻辑移位:右边丢弃，左边补0
//是逻辑右移还是算数右移取决于编译器
//基本上见过的都是算术右移。

//int main()
//{
//	int a = -7;
//	int b = a >> 1;
//	printf("a=%d\n", a); // -7
//	printf("b=%d", b);   // -4
//	return 0;
//}

//VS采用的是算术右移。
//对于移位运算符，不要移动负数位，也不能移动浮点数位，这是标准未定义的。

//位操作符

// & - 按(2进制)位与
// | - 按(2进制)位或
// ^ - 按(2进制)位异或
//int main()
//{
//	int a = 3; //补码 0000 0000 0000 0000 0000 0000 0000 0011
//	int b = -5;//原码 1000 0000 0000 0000 0000 0000 0000 0101
//	           //补码 1111 1111 1111 1111 1111 1111 1111 1011
//	int c1 = a & b; // & : 两个同时为1才是1，否则为0
//	int c2 = a | b; // | : 只要有1就为1，两个为0才为0
//	int c3 = a ^ b; // ^ : 相同为0，相异为1
//	printf("c1=%d\n", c1);  // 3
//	printf("c2=%d\n", c2);  // -5
//	printf("c3=%d\n", c3);  // -8
//	return 0;
//}

//不创建临时变量实现两个数的交换
//原本的方法1：(创建临时变量)
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	c = a;
//	a = b;
//	b = c;
//	return 0;
//}
//不创建法2：
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	return 0;
//}
//因为整型的数有最大值，可能相加会溢出。
//从理论上讲是有问题的

//不创建的法3
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	return 0;
//}

//两个相同的数字异或为0
// 0 ^ a = 0
// a ^ a = 0
// 3 ^ 3 ^ 5 = 5
// 3 ^ 5 ^ 3 = 5
// 注意：异或操作符支持交换律
// 所以：	a = a ^ b; b = a ^ b; a = a ^ b; -->
//          a = 3 ^ 5  b = 3 ^ 5 ^ 5 --> 3   a = 3 ^ 5 ^ 3 = 5;
// 而且这种算法不会溢出
//很难想，但是像加法

//在实际应用中，法1（创建临时变量）用得最广泛
//法3 只适用于 整型，处理速度较慢


//编写代码要求实现：求一个整数储存在内存中的二进制中1的个数
// ----> 求补码的二进制中1的个数

// int a = 3;
// 0000 0000 0000 0000 0000 0000 0000 0011
// 2 

// a & 1
// 0000 0000 0000 0000 0000 0000 0000 0011
// 0000 0000 0000 0000 0000 0000 0000 0001
//& 后 为 0000 0000 0000 0000 0000 0000 0000 0001 可以判断最后一位的是0还是1
// 只需要右移操作 第二位就变成第一位了

//int main()
//{
//	int a = 7;
//	int amount = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a & 1 )== 1)
//			amount++;
//		a = a >> 1;
//	}
//	printf("%d", amount);
//	return 0;
//}
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//
//输入例子:
//
//1999 2299
//
//输出例子 : 7
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((c & 1) == 1)
//			count++;
//		c >>= 1;
//	}
//	printf("%d", count);
//	return 0;
//}

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//#include<stdio.h>
//int main()
//{                                                // 0000 0000 0000 0000 0000 0000 0000 0101 
//	int a = 0;                                   // 1000 0000 0000 0000 0000 0000 0000 0001 
//	scanf_s("%d", &a);
//	int num = 1 << 30;
//	printf("Even digit:");
//	if (a >= 0)
//		printf("0 ");
//	else
//		printf("1 ");
//	for (int i = 0; i < 15; i++)
//	{
//		int b = (a & (num >> 1))/(num>>1);
//		printf("%d ", b);
//		num >>= 2;
//	}
//	num = 1 << 30;
//	printf("\nOdd digit: ");
//	for (int i = 0; i < 16; i++)
//	{
//		int b = (a & num)/num;
//		//b = Squ2(b);
//		printf("%d ", b);
//		num >>= 2;
//	}
//	return 0;
//}

//写一个函数返回参数二进制中 1 的个数。

//比如： 15    0000 1111    4 个 1
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a & 1) == 1)
//			count++;
//		a >>= 1;
//	}
//	printf("count = %d", count);
//	return 0;
//}

//赋值操作符
//  “ = ”

//int main()
//{
//	int a = 3; //初始化
//	a = 3;     //赋值
//	a = x = y + 1;//连续赋值，从右往左算 y+1的值赋给x x赋给a
//	//不建议连续赋值，无法单步进行调试，可读性较差， 建议不要用这个。
//	return 0;
//}

//复合赋值符号
//+= -= *= /= %=
// >>=  <<=  &= |= ^=

//单目操作符
//  ！ 逻辑反操作

//int main()
//{
//	int flag = 3;
//	//如果flag 为真（非0），if成立，进入条件语句
//	if(flag)
//	{ }
//	//如果flag 为假（0），！flag为真，if成立，进入条件语句
//	if (!flag)
//	{ }
//	return 0;
//}

// -负值 +正值 &取地址
//int main()
//{
//	int a = 30;
//	printf("%p\n", &a); //取的是变量在内存中的起始地址
//  int n = sizeof(a); //计算的是a所占内存的大小，单位是字节
// 

//	int * p = &a; //p 就是指针变量 存储地址
//	return 0;
//}

//sizeof 是一个操作符，不是函数
//计算的是变量、数组所占内存空间的大小
//strlen 是库函数，是用来求字符串的长度
// 
//  “ ~ ” 二进制位取反
//eg.
//int main()
//{
//	int a = 0;
//	// 0000 0000 0000 0000 0000 0000 0000 0000 
//	printf("%d\n", ~a);
//	// 1111 1111 1111 1111 1111 1111 1111 1111 补码
//	// 1111 1111 1111 1111 1111 1111 1111 1110 反码
//	// 1000 0000 0000 0000 0000 0000 0000 0001 原码
//	//     -----> -1
//	// 把其中几位变成1 可以这一位（1 << 几位） 或1 
//	// 把其中几位变成0 可以 0 按位与上去，其余全为1（a & ~(1<<4) ） 就可以
//	return 0;
//}

//前置++  先++ 后使用
//后置++  先使用，后++

// * 取地址操作符
// 如 p 是存放 &a a的地址，如果通过要通过p的地址找到a的地址，就是解引用p
// *p  --> 通过p里面的值找到 这个地址的所在的空间，就是 a  

//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr)); //打印了一个指针的大小 4个字节(x86)/8个字节(x64)
//}
//void test2(int ch[])
//{
//	printf("%d\n", sizeof(ch)); //打印了一个指针的大小 4个字节(x86)/8个字节(x64)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr)); //40
//	printf("%d\n", sizeof(ch));  //10
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//关系操作符
//  > >= < <= != ==
//注意：赋值与判断相等的区别
//注意：
//int main()
//{
//	if ("abc" == "abcdefg") //字符串这样比是在比较首字符的地址
//	{                       //需要用strcmp
//	};
//	return 0;
//}

//逻辑操作符
//   &&逻辑与 ||逻辑或
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);//1
//	int d = 0;
//	c = a && d;  //有一个0就为0
//	printf("%d\n", c);//0
//	c = a || b; //只要有一个为真则为真
//	printf("%d\n", c);//1
//	c = a || d;//1
//	printf("%d\n", c);//1
//	c = 0 || d;// 两个为0才为0
//	printf("%d\n", c);//0
//	return 0;
//}


//int main()
//{                 
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++; //只有a++算了，因为先使用a为0 不用算了
//	i = a++ || ++b || d++;  // 0 || 要算第二个，如果第二个为真，不用算了
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	//  &&1 2 3 4     ||：1 3 3 4
//	return 0;
//}
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++; // 无论前后置都++了
//	// i = a++||++b||d++;  //1 为真 后面根本不用算了，算到为真就好了
// 
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	// &&2 3 3 5  ||：1 2 3 5
//	return 0;
//}

//&&左边为假，右边不计算
//||左边为真，右边不计算

//条件操作符，（三目操作符）
//表达式1?表达式2:表达式3
//真         算        不算 
//假         不算      算

//int main()
//{
//	int a = 3;
//	int b = 0;
//	int max = (a > b ? a : b);
//	if (a > 3)
//		b = 3;
//	else
//		b = -3;
//	b = (a > 3 ? 3 : -3);
//	return 0;
//}

//逗号表达式
//从左往右依次计算，整个表达式的结果是最后一个表达式的结果

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = (a > b, a + b + 10, a, b = a + 1);//前面的计算不可以忽略
//	return 0;
//}

//下标引用操作符
// []
//int main()
//{
//	int arr[10] = { 0 };
//	arr[7] = 8;   //[]为下标引用操作符 []操作数为 arr 和 7 
//	return 0;
//}
//arr[7] --->  *(arr+7) arr+7就是跳过7个元素，指向了第八个元素，就是第八个元素
// ---->*(7+arr)  ---> 7[arr]  

//函数调用操纵符
//// ( ) 
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);//调用了,操作数为Add, a, b.
//	return 0;
//}

//访问一个结构的成员
//   .    结构体 . 成员名
//  ->     结构体指针->成员名
//struct Stu
//{
//	char name[20];
//	int age;
//	double score;
//};
//void set_stu(struct Stu*ps)
//{
//	// 不行，ss.name是一个地址，不能把字符串放到地址里。ss.name = "zhangsan";
//	//strcpy((*ps).name, "zhangsan");
//	//(*ps).age = 20;
//	//(*ps).score = 100.0;
//	strcpy(ps->name, "zhangsan");
//	ps->age = 20;
//	ps->score = 100.0;
//}
//void print_stu(struct Stu *ps)
//{
//	printf("%s %d %.1f\n", (*ps).name, (*ps).age, (*ps).score);
//}
//
//
//int main()
//{
//	struct Stu s = { 0 };
//	set_stu(&s);
//	print_stu(&s);
//	return 0;
//}
//实参传给形参的时候，形参是实参的一份临时拷贝。
//当你把s传过去的时候，只传递的是实参的值，然后对形参进行改变
//我们应该传递s的地址过去
// 然后 *ps 找到s的地址 后面用 (*ps).name 找到成员name
// 也可以用 ps -> name 找到


//-> 拿到了结构体指针—>成员名   ->不需要解引用
//如果拿到了结构体对象用. 成员名     ps->age 等价于 (*ps).age

//表达式求值
//表达式 看优先级和结合性

//隐式类型转换
//整型提升：C语言得整形算术运算总是至少以缺省整型类型的精度都来计算的。
//为了获得这个精度，表达式中的字符和短整型操作数在使用之前都会变成整型。
//整型提升的意义
//表达式的整形运算要在CPU的相应运算期间内执行
//，CPU内整型运算器(ALU)的操作数的字节长度一般就是int的字节长度，
//同时也是CPU的通用寄存器的长度。
//因此，即使两个char类型的相加，
//在CPU执行时实际上也要先转换为CPU内整形操作数的标准长度。
//通用CPU(general-purpose CPU)是难以直接实现两个8byte字节直接相加运算
//(虽然机器指令中可能有这种直接相加指令)。
//所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigend int
//然后才能送入CPU中去执行

//如何进行整型提升呢？
//整型提升是按照变量的数据类型的符号位来提升的。

//int main()
//{
	//char c = -1; //-1是整数，32个比特位
	// 1000 0000 0000 0000 0000 0000 0000 0001
	// 1111 1111 1111 1111 1111 1111 1111 1110
	// 1111 1111 1111 1111 1111 1111 1111 1111 ->  -1 的 补码
	// 因为char类型只有一个字节，8比特位
	// 1111 1111
	//把第一个看成是符号位，高位补充符号位。
	//char d = 1;
	// 0000 0000 0000 0000 0000 0000 0000 0001
	// 0000 0001;
	//高位补符号位0
//如果为无符号数，直接补0
//return 0;
//}

//int main()
//{
//	char a = 5;
//	// 0000 0000 0000 0000 0000 0000 0000 0101
//	// 0000 0101
//	char b = 126;
//	// 0000 0000 0000 0000 0000 0000 0111 1110
//	// 0111 1110
//	char c = a + b;
//	//整型提升
//	// 0000 0000 0000 0000 0000 0000 0000 0101
//	// 0000 0000 0000 0000 0000 0000 0111 1110
//	// 0000 0000 0000 0000 0000 0000 1000 0011
//	//回退 八个比特位
//	// 1000 0011
//	printf("%d", c);
//	//整型提升
//	// 1111 1111 1111 1111 1111 1111 1000 0011
//	// 1111 1111 1111 1111 1111 1111 1000 0010
//	// 1000 0000 0000 0000 0000 0000 0111 1101
//	// -125！！
//	return 0;
//}
// char -128 - 127

//int main()
//{
//	char a = 0xb6;
//	//整型提升了
//	//可能会改变值，因为符号位可能为1
//	short b = 0xb600;
//	//整型提升了
//	//可能会改变值，因为符号位可能为1
//	int c = 0xb60000;
//	
//	return 0;
//}

//放在表达式中，整型就会提升，比如 +c
//int main()
//{
//	char c = 1;
//	printf("%d", sizeof(c)); //1
//	printf("%d", sizeof(+c)); //4
//	printf("%d", sizeof(-c));//4
//
//	return 0;
//}

//比如float 和 double 一起运算，会向上转换
//int 和double 遇到了 ，int 会提升成double，
//都是向上转换。

//操作符的属性
//复杂表达式的求值有三个影响因素
//1.优先级：相邻操作符的优先级
//2.结合性：相邻操作符优先级相同的时候，结合性说了算
//  L-R 从左向右 R-L 从右向左
//3.是否控制求值顺序，如逻辑或，算到1就不用算了
//
//但是面对一些表达式
//他们的顺序没法控制，有多种解释方法
//  c + --c
//    2  1 
//  一定是先算右边的 --c 
// 但是左边的 c 什么时候准备呢
// 如果c 等于2， 先--c 后准备c 则结果为2
// 如果 先准备c 后--c 则结果为3
// 
// a * b + c * d + e * f
//

//#include <stdio.h>
//int i;
//int main()
//{
//	i--;
//	if (i > sizeof(i))
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}
// 会输出>

//KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的X形图案。
//输入描述：
//多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
//输出描述：
//针对每行输入，输出用“ * ”组成的X形图案。

//#include<stdio.h>
//void Init(char arr[20],int a)
//{
//	for (int i = 0; i < a; i++)
//	{
//		arr[i] = ' ';
//	}
//}
//void Replace(char arr[20], int a,int b)
//{
//
//	arr[a - 1] = '*';
//	arr[b] = '*';
//}
//void Print(char arr[20], int a)
//{
//	for (int i = 0; i < a; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	char arr[20] = { 0 };
//	int a = 0;
//	int b = 0;
//	scanf_s("%d", &a);
//	int a1 = a;
//	Init(arr,a);
//	for (int i = 0; i < a; i++)
//	{
//		Replace(arr, a1, b);
//		Print(arr, a);
//		Init(arr, a);
//		a1--;
//		b++;
//	}
//	return 0;
//}
//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int row = 0;
//	scanf_s("%d", &row);
//	char arr[21][21] = { 0 };
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			if (j == i || j == row - 1 - i)
//				arr[i][j] = '*';
//			else
//				arr[i][j] = ' ';
//			printf("%c", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起

//#include<stdio.h>
//int main()
//{
//	int row = 0;
//	while (scanf_s("%d", &row) != EOF);
//	{	char arr[21][21] = { 0 };
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			if (j == i || j == row - 1 - i)
//				arr[i][j] = '*';
//			else
//				arr[i][j] = ' ';
//			printf("%c", arr[i][j]);
//		}
//		printf("\n");
//	}
//	}
//	return 0;
//}

//找到规律是关键，看作一条正斜杠和反斜杠
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	while (scanf_s("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)  //外循环为行
//		{
//			for (int j = 0; j < n; j++) //内循环为列
//			{
//				if (i == j || i + j == n - 1)
//					//最关键的地方，正斜线为[i][i]处是*， 反斜杠为[i][n-1-j]处是*，一行打印1个或2个*
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n"); //打印完一行，换行
//		}
//	}
//	return 0;
//}
//
//描述
//KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
//输入描述：
//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。

//int is_leap_year(int x)
//{
//	if (x % 400 == 0)
//		return 1;
//	else if (x % 4 == 0 && x % 100 != 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	while (scanf_s("%d %d", &year, &month) != EOF)
//	{
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//			printf("31");
//		else if (month == 2)
//		{
//			int ret = is_leap_year(year);
//			printf("%d", ret == 1 ? 29 : 28);
//		}
//		else
//			printf("30");
//	}
//	return 0;
//}
 

//KiKi想知道已经给出的三条边a，b，c能否构成三角形，如果能构成三角形，判断三角形的类型（等边三角形、等腰三角形或普通三角形）。
//输入描述：
//题目有多组输入数据，每一行输入三个a，b，c(0 < a, b, c < 1000)，作为三角形的三个边，用空格分隔。
//	输出描述：
//	针对每组输入数据，输出占一行，如果能构成三角形，等边三角形则输出“Equilateral triangle!”，等腰三角形则输出“Isosceles triangle!”，其余的三角形则输出“Ordinary triangle!”，反之输出“Not a triangle!”。

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (scanf_s("%d %d %d", &a, &b, &c) != EOF)
//	{
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if (a == b && b == c)
//				printf("Equilateral triangle!\n");
//			else if (a == b || b == c || a == c)
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//			printf("Not a triangle!\n");
//	}
//	return 0;
//}