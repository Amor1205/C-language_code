#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//字符指针
//char*类型的指针
//有两种书写的形式

//int main()
//{
//	//char ch = 'a';
//	//char* pc = &ch;
//	//*pc = 'b';
//	//printf("%c\n", ch);
//	//上面是字符指针的一个写法
//	//
//	const char* p = "abcdef"; 
//	//这是一个字符串，
//	//这是把字符串首字符a的地址赋值给p
//	//打印的时候以a的地址为起始地址，打印到\0中止
//	// 最好加const 否则可能会改*p的内容
//	// 但是 这种不能改内容。
//	// 
//	//int a = 10;
//	// int b = a + 2;
//	// 
//	//b 值属性 12
//	//类型属性 int 
//
//
//	printf("%s\n", p);
//
//	return 0;
//}

//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	char arr1[] = "abcedf";
//	char arr2[] = "abcedf";
//	if (p1 == p2)
//		printf("p1==p2\n");
//	if (arr1 == arr2)
//		printf("arr1==arr2");
//	//发现p1 == p2 ,arr1 != arr2
//	//p1 和 p2指向了同一个字符串，常量字符串
//	// 在内存中存的只读的字符串，如果内容相同，在内存中就只会存放一份。
//	//
//	return 0;
//}

//指针数组是数组 是用来存放指针的数组
// int arr[10] 整型数组
// 整形指针数组 int * arr2[6];
// 字符指针数组 char* arr3[5];
//   
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[3] = { arr1,arr2,arr3 };
//	//parr的每个元素的类型都是int*
//	//如果想用parr打印34567
//	for (int i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//指针数组就是可以模拟二维数组 
// *(parr+j) -->  parr[i][j]
//但是 parr中的三个数组不一定是连续存放的
//而二维数组的是连续存放的
//
//数组指针 --- 指针 是指向数组的指针
//类比于整型指针 指向整形的指针
//int *p1[10] ----> p1 数组指针 
// int (*p2)[10]  ----> p2 指针数组  指向了一个十个元素的数组 每个元素是int类型
//
//讨论数组名
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	//arr 首元素地址
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	int sz = sizeof(arr);
//	//arr 不是首元素地址
//	printf("%d\n", sz);
//
//	//存放&arr
//	int(*p2)[10] = &arr;
//	//数组指针
//
//	char* arr[5] = { 0 };
//	char* (*pc)[5] = &arr;
//	//必须写[5] 不能空着
//	return 0;
//}
//总结：
//数组名通常都是表示的是数组的首元素地址
//但是有两个例外：
//1.sizeof 内部单独放一个数组名   --- sizeof(arr)
// 这里的数字名表示整个数组，计算的是整个数组的大小。
//2. &数组名
//  &arr 这里的数组名表示的依然是整个数组，所以去除的是整个数组的地址
// 理解：
// &arr 与 &arr+1 跳过了整个数组 指向数组末尾的下一位的地址 
// 
// 再结合数组指针是存放数组的地址
// 
//错误的用法：可以用，但是麻烦且别扭
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", *(*p+i));
//		//非常之别扭！！！！
//	}
//	return 0;
//}
//正确的用法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *p + i);
//	}
//	return 0;
//}

//如果用数组指针，至少用在二维数组上才方便一些。
//
//void print1(int arr[3][5], int c, int r)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		for (int j = 0; j < r; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int(*p)[5], int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(p + i)+j));
//			//*p是arr首元素地址，就是第一行的地址，地址需要再解引用
//		}
//		printf("\n");
//	} 
//}

//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	print1(arr, 3, 5);
//	printf("----------\n");
//	print2(&arr, 3, 5);
//	
//	return 0;
//}
//二维数组首元素是他的第一行的地址
//一行当成一个元素
//

//解析
// int arr[5] 整型数组
// int *parr1[10] parr1是整形指针数组，有十个元素每个元素都是int*
// int (*parr2)[10] parr2是数组指针
// int (*parr3[10])[5] 
// 拆分开，parr3[10] 在一起，类型为 int(* )[5] 
// 所以应该是存放数组指针的数组
// parr3后面的10 代表着可以存放十个数组，5 代表 每个数组都有五个元素
//


//4.数组参数、指针参数
//写代码时难免吧数组或指针传给函数，那函数的参数如何设计呢？
// 一维数组传参
// 
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	//可以写成数组形式不填元素个数
//	//可以写成指针
//	//可以写成数组形式填元素个数
//	test2(arr2);
//	//arr2是整形指针数组
//	//可以写成数组形式，int *arr[20] 类型+元素个数
//	//arr2看作首元素地址，int*类型，用二级指针存放，int** arr
//	//
//	return 0;
//}

//二维数组传参
// 
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//	//int arr[3][5] 可以
//	//不可以用int arr[][]  --- 形参的二维数组行可以省略，列不能省略。
//	//int arr[][5] 可以
//	//二维数组的数组名，表示首元素的地址，其实是第一行的地址
//	// 第一行是一个一维数组
//	// int (*arr)[5]可以
//	// 不可以用int **arr 二级指针 不行
//	// 二级指针是存放一级指针的地址的，不能用来存数组
//	//
//	return 0;
//}

//一级指针传参
// 如果使用指针传参，使用什么指针，就用什么指针接受
// 但如果函数的参数部分是指针
// 比如
// int a = 10;
// int *ptr = &a
// 传递a 用 &a, 用 ptr，用一维数组数组名 都可以
// 
//

//二级指针传参
//
//int n = 10;
//int* p = &n;
//int** pp = &p;
//test(pp);
//test(&p);

//如果函数的形式参数是二级指针，调用函数的时候可以传什么实参呢？
//test (int ** p)

//int* p1;
//int** p2;
//int* arr[10];//指针数组的数组名可以传给二级指针形参
//test(&p1);
//test(p2);
//test(arr)//可以传指针数组


//函数指针
//
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int arr[5] = { 0 };
	int(*p)[5] = &arr;
	//p是指向数组的指针
	//函数名，取出的是函数的地址
	//
	printf("%p\n", &Add);
	printf("%p\n", Add);
	//对于函数来说，&函数名和函数名都是函数的地址
	//如何存 &Add？

	int(*pf)(int ,int) = &Add;
//  返回类型
	//代表指针，(*pf)一定要放到括号里去
	         //传参类型
	//把一个数值的地址存起来是为了修改和访问
	//把函数的地址存起来也是
	//解应用！
	int ret = (*pf)(2, 3);
	//*可以不写
	// 但如果要写一定要放在括号里
	int ret2 = pf(2, 3);
	// 因为pf就是Add
	//新的调用函数的方式
	printf("%d", ret);
	return 0;
}