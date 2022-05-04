#define _CRT_SECURE_NO_WARNINGS

//函数
//是一个子程序
//相较于其他代码具有独立性
//一般会有输入参数并有返回值，提供对过程的封装和细节的隐藏，这些代码通常被集成为软件库

//分类：
//1.库函数
//2.自定义函数

//1.1为什么会有库函数？
// 
//有一些函数我们会频繁的使用
//比如 求字符串长度 strlen
//比如 比较两个字符串大小 strcmp
//比如 打印数据 printf
//比如 确定数组的字节数 sizeof
//做了库函数，代码书写效率提升，出现bug可能性减少
// http://www.cplusplus.com/reference/
//简单总结函数类型
// IO函数
// 字符串操作函数
// 字符操作函数
// 内存操作函数
// 时间/日期函数
// 数学函数
// 其他库函数

//如： strcpy
// Copy string
// char * strcpy(char * destination, const char * source);
//including 结束的 字符 \0

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello bit!";
//	strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//都可以去参考上面的网站
// 函数名
// 函数原型
// 详细介绍
// Parameters描述形式参数
// Return Values 返回值
// Examples
// See also 类似的其他的。

//exm2： memset
//void * memset (void * ptr, int value, size_t num)
//               数组名                 size_t  无符号整型
// fill block of memory (memory 内存)
//sets the first num bytes of the bolck of memory pionted by ptr to the specified value(interpreted as an unsigend char).


//int main()
//{
//	char arr[20] = "hello world";
//	memset(arr, 'x', 5);//把前五个字符变成x
//	memset(arr+6, 'y', 3);// +6 偏移6个字符 ，把wor变成y
//	printf("%s", arr);  
//	return 0;
//}

//1.2自定义函数
//自定义函数和库函数一样，有函数名，返回值类型和函数参数
//自定义函数需要程序员自己设计。

//ret_type fun_name(paral, *)
//{
//	stratment; //语句项    {和内部} 叫 函数体
//}

//写一个函数求两个整型的最大值

//#include<stdio.h>
//调试 F10 往下走 F11 进入函数内部
//int get_MAX(int x, int y)     //函数的定义   
//{
//	return(x > y ? x : y);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_MAX(a, b);    //函数的调用
//	printf("%d", m);
//	return 0;
//}

//写一个函数交换两个变量的内容
//#include<stdio.h>
//
//void Swap(int x, int y)
//{
//	int t = 0;
//	t = x;
//	x = y;
//	y = t;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("交换前：a=%d,b=%d\n", a, b);
//	Swap(a, b);
//	printf("交换后：a=%d,b=%d\n", a, b); //10 20
										 //交换前：a = 10, b = 20
										 //交换后：a = 10, b = 20
//	return 0;
//}
//为什么没有交换？
//实际参数 a 和 b
//形式参数 x 和 y
//当 实参 传递给 形参 的时候， 形参 是 实参的一份临时拷贝
//对 形参 的修改 不会影响实参。

//int main()
//{
//	int a = 10;
//	int* p = &a;   //指针
//	a = 20; // 直接改
//	*p = 20 // 间接改
//	return 0;
//}


//#include<stdio.h>
//
//void Swap(int *px, int *py)
//{
//	int t = 0;
//	t = *px;
//	*px = *py;
//	*py = t;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("交换前：a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后：a=%d,b=%d\n", a, b); 
//	return 0;
//}
//交换成功
// 
//形参 和 实参 如何建立联系？
//用 指针   取地址去建立联系。
// &a      &b
// int *px int *py

//#include<stdio.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = add(a, b);
//	printf("%d", c);
//	return 0;
//}

//为什么add函数不用取地址，而swap需要呢？
//因为 add函数并不改变 a，b的值，而swap函数需要改变本来的a和b的值
//通过指针远程找回a和b，需要用取地址再解取*px

//3.函数的参数
//3.1实际参数 实参
//真实传递给函数的参数叫实参。
//实参可以是：常量，变量，表达式，函数等
//无论是实参是何种类型的量，在进行函数调用时，都必须有确定的值，以便把这些值都传递给形参

//3.2形式参数 形参
//形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配内存单元）
//所以叫形式参数，形式参数只在函数范围内有效，出函数销毁。
//形参实例化后是实参的一份临时拷贝

//！！！实参和形参的名字可以相同，也可以不同

//4.函数调用
//4.1传值调用
// 函数的实参和形参分别占有不同的内存块，地址并不相同
//4.2传址调用
//把函数外部创建变量的内存地址传递给函数参数
//这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量

//函数的应用
//写个函数判断是不是素数

//#include<stdio.h>
//void Judge(int x)
//{
//	int i;
//	int flag = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("%d不是素数\n",x);
//			flag = 0;
//			break;
//		
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if(1 == flag)
//	{
//		printf("%d是素数\n", x);
//	}
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	Judge(a);
//	return 0;
//}


//100-200中的素数

//#include<stdio.h>
//void Judge(int x)
//{
//	int i;
//	int flag = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("%d不是素数\n", x);
//			flag = 0;
//			break;
//
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (1 == flag)
//	{
//		printf("%d是素数\n", x);
//	}
//}
//int main()
//{
//	int j = 100;
//	for (j = 100; j <= 200; j++)
//		Judge(j);
//	return 0;
//}

//优化：发现 m = a * b时，a和b中一定有一个数字是 <= sqrt(m)的
//修改函数部分
//#include<stdio.h>
//#include<math.h>
//void Judge(int x)
//{
//	int i;
//	int flag = 0;
//	for (i = 2; i < sqrt(x); i++)   //sqrt(x)数学函数，用math.h
//	{
//		if (x % i == 0)
//		{
//			printf("%d不是素数\n", x);
//			flag = 0;
//			break;
//
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (1 == flag)
//	{
//		printf("%d是素数\n", x);
//	}
//}

//偶数一定不是素数，所以可以从调用函数时调整它
//int main()
//{
//	int j = 100;
//	for (j = 101; j <= 200; j+=2)
//		Judge(j);
//	return 0;
//}

//老师讲的 判断
//return 语句比break强大许多，如果用return 可以直接跳出函数

//#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i < 200; i += 2)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d  ", i);
//			count += 1;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//写一个函数判断一年是不是闰年
//#include<stdio.h>
//int JUDGE(int x)
//{
//	if (x % 4 == 0)
//	{
//		if (x % 100 == 0)
//		{
//			if (x % 400 == 0)
//				return 1;
//			else
//				return 0;
//		}
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (JUDGE(year) == 1)
//		printf("%d ", year);
//	else
//		printf("不是闰年\n");
//	return 0;
//}

//1000-2000中输出所有的闰年，并且计数
//#include<stdio.h>
//int JUDGE(int x)
//{
//	if (x % 4 == 0)
//	{
//		if (x % 100 == 0)
//		{
//			if (x % 400 == 0)
//				return 1;
//			else
//				return 0;
//		}
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year = 1000;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (JUDGE(year) == 1)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d ", count);
//	return 0;
//}

//更简单的： 用&& ||

//#include<stdio.h>
//
//int JUDGE(int x)
//{
//	if (((x % 4 == 0)&& (x % 100 != 0))||(x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 1000;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (JUDGE(year) == 1)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d ", count);
//	return 0;
//}

//我们在写函数的时候，最好把函数的功能变单一，变简单。
//高内聚低耦合：自己尽量不要和别人的功能相关


//写函数实现二分查找

//#include<stdio.h>
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while(left<=right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 6;
//	int sz = sizeof(arr) / sizeof(arr[0]);
	//找到了，返回下标
	//找不到，返回-1
//	int ret = binary_search(arr, k,sz);
//	if (ret != -1)
//		printf("找到了，下标是%d\n", ret);
//	else
//		printf("找不到\n");
//	return 0;
//}

//数组传参并不是又存储了另一个数组的内存，而是创建了一个指针变量 
//那sizeof（指针变量） 是4 或者 8 （32位电脑x86 是 4 ， x64 是 8）
//所以在函数内部计算一个函数参数部分的数组元素个数是不靠谱的。

//布尔类型 c99引入的 bool
//用来表示真假的变量
//如何用？  <stdbool.h>

//#include<stdbool.h>
//
//bool is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return false;
//	}
//	return true;
//}
//bool 用的不多，因为c99才引入，bool用一个字节。


//写一个函数，每调用一次这个函数，就会将num 的值增加1
//#include<stdio.h>
//void ADD(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	ADD(&num);
//	printf("%d\n", num);
//	ADD(&num);
//	printf("%d\n", num);
//	ADD(&num);
//	printf("%d\n", num);
//	return 0;
//}

//5嵌套调用和链式访问
//5.1 嵌套调用
//函数可以互相调用的
//！！！但是不可以嵌套定义的。不能把一个函数的定义放在一个函数里面，
//因为函数的地位都是平等的。

//5.2 链式访问
//依赖的是函数的返回值
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", strlen("abcdef"));
//	printf("%d\n", len);
//}
//两个输出值相同，是因为把strlen("abcdef")函数的返回值，作为了printf的参数，这就叫链式访问。

//经典的链式访问
//#include<stdio.h>
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));  //4321
//}
//这是因为printf函数的返回值是字符打印的个数 
//43 是两个字符， 返回值就是2 ， 2 是1个字符 ，返回值为1.故4321
//链式访问的前提是 ： 函数有返回值
//函数不写返回值的时候，默认返回类型是int，默认返回最后一条指令的返回值，写法非常不准确，应该明确给出返回值。
//但是！！ 不建议不写返回值

//如果不需要test() 内部的参数，我们可以明确拒绝。 定义test()时，使用test(void)

//本质上main函数有三个参数
//int main(int argc,char* argv[], char *envp[])


//6.1 函数的声明
//函数返回类型 名字（参数类型）
//int Add(int ,int);
//如果函数在后面，或者在其他的文件中，可以声明一下然后取消警告。
//函数声明一般放在头文件中

//头文件：
//创建函数名为源文件名的.c文件
//创建与源文件同名的.h头文件，声明函数。

//在初学编程的时候，觉得把所有的代码写到一个文件中最方便。
//但是，在公司中不是这么写的
//从协作角度，模块化角度考虑

//声明和定义分开的好处：

//#include<stdio.h>
//int Add(int, int);
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}

//VS里面右击 项目类型 修改exe成.lib 静态库
//导入静态库 #pragma comment(lib,"add.lib");
// #pramga once 头文件只包含一次

//7 函数递归
//程序调用自身的编程技巧成为递归 recrusion
//只需少量的程序就可以描述出解题过程所需要的多次重复计算，大大减少了程序的代码量。
//核心思想：大事化小

//接受整型值，按顺序打印他的每一位
//例如：
//输入：1234，输出1 2 3 4

//%d 打印有符号整数（有正负数）
//%u 无符号整数
//#include<stdio.h>
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	for (; num != 0;)
//	{
//		int a = num % 10;
//		num = num / 10;   //num /=10;
//		printf("%d ", a); //顺序反了！！！ 4 3 2 1
//	}
//	return 0;
//}

//用递归
//1234拆分成 123 每一位 + 4
//123 拆分成12的每一位  + 3
//12  拆分成1           + 2
//#include<stdio.h>
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}
//递归的必要条件
// 
//递归一定要写限制条件
//否则会栈溢出 Stack overflow
//每次递归调用之后越来越接近这个限制条件

//练习2：编写函数不允许创建临时变量，求字符串的长度
//模拟strlen
// 

//int my_strlen(char* str) //参数部分写成指针的形式
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		 count++;
//		 str++;   //找下一个字符  一个字符一个字节
//	}
//	return count;
//}
//#include<stdio.h>
//int main()
//{
//	char ch[20] = "arrrwrar";
//	//scanf("%d", ch); //传过去首字符地址，接受用char*接受
//	int len = my_strlen(ch);
//	printf("%d\n", len);
//	return 0;
//}

//用递归！
//#include<stdio.h>
//my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str+1); //是+1 不是 ++ 后置++ 有副作用的，会变str的值
//	else
//		return 0;
//}
//int main()
//{
//	char ch[20] = "arrrwrar";
//	int len = my_strlen(ch);
//	printf("%d\n", len);
//	return 0;
//}

//迭代:用循环的方法
//求n的阶乘
//如果我用递归
//#include<stdio.h>
//int fac(int x)  
//{
//	if (x != 0)
//		return x * fac(x - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("ret = %d", ret);
//	return 0;
//}

//求第n个斐波那契数
//1 1 2 3 5 8 .
//#include<stdio.h>
//int fib(int x)
//{
//	if (x > 2)
//		return fib(x - 1) + fib(x - 2);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = fib(n);
//	printf("%d", num);
//	return 0;
//}
//如果求n = 40 的斐波那契数，计算效率实在很低
//有大量的重复运算
//可见，递归有的时候效率很低

//用迭代
//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 1;
//	int c = 2;
//	int n;
//	int count = 2;
//	scanf("%d", &n);
//	while(count != n)
//	{ 
//		c = a + b; 
//		count++;   
//		a = b;     
//		b = c;     
//	}
//	printf("%d", c);
//	return 0;
//}

//迭代法2
//#include<stdio.h>
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = Fib(n);
//	printf("%d", num);
//	return 0;
//}

//递归如果递归次数太多，层次太深，容易出现栈溢出的形式
//解决办法：
//1.递归改成非递归
//2.静态变量改为static对象，将存放在栈上的静态变量改为存在静态区上的static变量


//递归思想 题目
//汉诺塔题目 比特大博哥
//青蛙跳台阶问题  C语言刷题训练营
