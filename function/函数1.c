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

//输入一个值a 输出 a * a 乘法口诀表

//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	scanf("%d", &a);
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}