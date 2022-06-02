#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	//指针数组
//	int* arr[4];
//	char* ch[5];
//
//	int** p = arr;
//	//二级指针存放指针数组中的首元素地址。
//
//	//数组指针
//	int arr2[5];
//	int(*pa)[5] = &arr2;
//	//pa指向了5个元素，数组的类型是int
//	//
//	char* arr3[6];
//	char(*p3)[6] = &arr3;
//
//	return 0;
//}
//int test(const char* str)
//{
//	return 0;
//}
//int main()
//{
//	//函数指针 - 也是一种指针，是指向函数的指针
//	//函数的地址用函数名或取地址函数名
//	int(*pf)(const char*) = test;
//	//使用函数 -- 3种方法
//	(*pf)("abc");
//	pf("abcd");
//	test("abcde");
//	return 0;
//}

//int main()
//{
//	//(*( void(*)() ) 0 )();
//	// 0 是什么？
//	// void(*p)()  p是函数指针
//	// 所以viod (*)()是函数指针类型
//	// 0 本身是一个整数
//	// （类型）其实是强制类型转换
//	//  认为0是 被强制类型转换为：无参数，返沪类型为viod的函数的地址
//	//  * 解引用 ，调用0地址处的这个函数
// 
//	void(*signal(int, void(*)(int)))(int);
//	// 拆分 void ( * ) (int) 名称是signal 
//	// signal肯定是和后面括号相结合，所以就是函数名
//	// 因为指针的后面不会出现(int,void.....)
//	// 
//	// 以上代码是一次函数声明
//	// 声明的signal函数的第一个参数的类型是int，
//	// 第二个参数的类型是函数指针，该函数指针指向的函数参数是int，返回类型是void
//	// signal函数的返回类型是一个函数指针。
//	// 可以简化  typedef --- 给类型重命名
//	typedef void(*pf_t)(int);  //把viod(*)(int)类型重命名为pf_t
//
//	return 0;
//}


//函数指针的用途
//
//写一个计算器
//加法、减法、乘法、除法
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************1.ADD 2.SUB **************\n");
//	printf("***************3.MUL 4.DIV **************\n");
//	printf("**************** 0.EXIT *****************\n");
//	printf("*****************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// float Div(float x, float y)
//{
//	 return (float)x / (float)y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	float m = 0.0;
//	float n = 0.0;
//	float retu = 0.0;
//	do {
//		menu();
//		printf("选择--->\n");
//		scanf("%d", &input);
//		if (1 == input || 2 == input || 3 == input)
//		{
//			printf("输入操作数--->\n");
//			scanf("%d %d", &x, &y);
//		}
//		else if (4 == input)
//		{
//			printf("输入操作数--->\n");
//			scanf("%f %f", &m, &n);
//		}
//		switch (input)
//		{
//		case 1:
//			ret = Add(x,y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			ret = Sub(x,y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			ret = Mul(x,y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			retu = Div(m, n);
//			printf("%.2f\n", retu);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("数据非法，请重新输入:>\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//函数冗余
//
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************1.ADD 2.SUB **************\n");
//	printf("***************3.MUL 4.DIV **************\n");
//	printf("**************** 0.EXIT *****************\n");
//	printf("*****************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// float Div(float x, float y)
//{
//	 return (float)x / (float)y;
//}
// void calc(int(*pf)(int x, int y))
//{
//	 int x = 0;
//	 int y = 0;
//	 printf("输入操作数--->\n");
//	 scanf("%d %d", &x, &y);
//	 int ret = 0;
//	 ret = pf(x, y);
//	 printf("%d\n", ret);
//}
//int main()
//{
//	int input = 0;
//
//	float m = 0.0;
//	float n = 0.0;
//	float retu = 0.0;
//	do {
//		menu();
//		printf("选择--->\n");
//		scanf("%d", &input);
//
//		if (4 == input)
//		{
//			printf("输入操作数--->\n");
//			scanf("%f %f", &m, &n);
//		}
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			retu = Div(m, n);
//			printf("%.2f\n", retu);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("数据非法，请重新输入:>\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


////函数指针数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	 return x / y;
//}
//int main()
//{
//	int(*pf)(int,int) = Add;
//	int(*arr[4])(int, int) = { Add,Sub,Mul,Div };
//	//arr就是函数指针的数组
//	//要求函数的返回值相同参数相同
//	//调用
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d  ",arr[i](8,4));
//	}
//	return 0;
//}


//函数指针数组的使用
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************1.ADD 2.SUB **************\n");
//	printf("***************3.MUL 4.DIV **************\n");
//	printf("**************** 0.EXIT *****************\n");
//	printf("*****************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	 return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int (*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//
//	do 
//	{
//		menu();
//		printf("选择--->\n");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//		}
//		else if (input>=1&&input<=4)
//		{
//			printf("输入操作数--->\n");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("非法，重新输入\n");
//		}
//	} while (input);
//	return 0;
//}

//指向函数指针数组的指针

//int main()
//{
//	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	//指向函数指针数组的指针
//	&pfArr;
//	int(*(*ppfArr)[5])(int, int) = &pfArr;
//
//	return 0;
//}

//回调函数
//回调函数就是一个通过函数指针调用的函数
//如果你把函数的指针（地址）作为参数传递给另外一个函数
//当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。
// 回调函数不是有该函数的实现方直接调用
//

//冒泡排序
//只能排序整型数据
//void bubble_sort(int arr[], int sz)
//{	
//	int flag = 1;
//	//假设数组是有序的。（已经排好序了）
//	// 
//	//冒泡排序的套数
//	for (int i = 0; i < sz - 1; i++)
//	{
//		//一套冒泡排序的过程
//		//相邻的两个元素的比较
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			//换顺序
//			if (arr[j] > arr[j + 1])
//			//整型才可以用大于号小于号比较
//			//不同数据的比较方法不同 可以用cmp函数比较
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}

//qsort 库函数
//这个函数可以排序任意类型的数据
//
//
//void qsort(
//	void* base,//你要排序的数据的起始位置
//	size_t num,//待排序的数据元素的个数
//	size_t width,//待排序的数据元素的大小（单位是字节）
//	int(*cmp)(cosnt void* e1, cosnt void* e2));（函数指针 -- 比较函数）
//  不同数据的比较函数是cmp，这个函数需要程序员自己提供
// 如果e1大于e2，输出大于0的数
// 如果等于，输出0
// 如果小于，输出小于0的数

//如比较两个int元素
//e1与e2指向两个整数
//int cmp_int(const void* e1, const void* e2)
//{
//	//错误做法：if(*e1>*e2)
//	//void*的类型是不可以直接解引用的。
//	//void* 是无具体类型的指针，所以不能接引用操作，也不能加减整数
//	// 所以需要强制类型转换为int*
//	return (*(int*)e1 - *(int*)e2);
//}
//
//void test1()
//{
//	int arr[] = { 8,7,5,4,3,1,2,9,10,0 };
//	//把数组排成升序；
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test2()
//{
//	//用qsort排序结构体数据
//	struct Stu s[] = { {"zhangsan",15},{"wangwu",29} ,{"lisi",19} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//int main()
//{
//	//test1();
//	test2();
//}

void swap(char*e1, char*e2,int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int flag = 1;
	//假设数组是有序的。（已经排好序了）
	// 
	//冒泡排序的套数
	for (int i = 0; i < sz - 1; i++)
	{
		//一套冒泡排序的过程
		//相邻的两个元素的比较
		for (int j = 0; j < sz - i - 1; j++)
		{
			//换顺序
			if (cmp((char*)base + j * width), (char*)base + (j + 1) * width > 0)
				//转换成char*才最细，否则int*加1跳过4个字节
				//
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}