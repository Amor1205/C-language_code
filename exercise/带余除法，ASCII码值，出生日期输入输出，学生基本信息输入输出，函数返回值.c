#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//Q1： 求带余除法。
//int main()
//{
//	int a = 0;
//	int b = 0;
//	//输入
//	scanf("%d %d", &a, &b);
//	int c = a / b; // 商
//	int d = a % b; // 余数
//	printf("%d %d", c, d);
//	return 0;
//}

//Q2
//BoBo教KiKi字符常量或字符变量表示的字符在内存中以ASCII码形式存储。BoBo出了一个问题给KiKi，转换以下ASCII码为对应字符并输出他们。
//73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33

//int main()
//{
//	int a[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };
//	int length = sizeof(a) / sizeof(a[0]);
//	int i;
//	for (i = 0; i < length; i++)
//
//	{
//		printf("%c", a[i]);      // char数值用%c打印。
//	}
//	return 0;
//}

//Q3:输入输出学生信息
//描述
//输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出。
//
//数据范围：年份满足 1990 < y < 2015 ，月份满足  1≤m≤12  ，日满足 1≤d≤30
//输入描述：
//输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
//输出描述：
//三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。

//int main()
//{
//	int y = 0;
//	int m = 0;
//	int d = 0;
//	scanf("%4d%2d%2d", &y, &m, &d);      //  %4d 是说打印四位的整型，
//	printf("year=%d\nmonth=%02d\ndate=%02d\n", y, m, d);    //  %02d 可以把 2 变成02 输出
//	return 0;
//}

//Q4：学生基本信息输入输出
//描述
//依次输入一个学生的学号，以及3科（C语言，数学，英语）成绩(三位小数)，在屏幕上输出该学生的学号，3科成绩（注：输出成绩时需进行四舍五入且保留2位小数）。
//
//数据范围：学号满足 1≤n≤20000000  ，各科成绩使用百分制，且不可能出现负数
//输入描述：
//学号以及3科成绩，学号和成绩之间用英文分号隔开，成绩之间用英文逗号隔开。
//输出描述：
//学号，3科成绩（两位小数），输出格式详见输出样例。

//int main()
//{
//	int a;
//	float arr[3];
//	scanf("%d;%f,%f,%f", &a, &arr[0], &arr[1], &arr[2]);
//	int i;
//	float arr2[3];
//	float arr3[3];
//	for (i = 0; i < 2; ++i)
//	{
//		arr2[i] = arr[i] * 1000) % 10;
//		if (arr2[i] >= 5)
//		{
//			arr3[i] = ((arr[i] * 1000 - b) + 10) / 1000.0;
//		}
//		else
//		{
//			arr3[i] = (arr[i] * 1000 - b) / 1000.0;
//		}
//	}
//
//	printf("%1d,%.2f,%.2f,%.2f", a,arr3[0], arr3[1], arr3[2]);
//	return 0;
//}
//
//#include<stdio.h>
int main()
{
	int a;
	float arr[3];
	scanf("%d;%f,%f,%f", &a, &arr[0], &arr[1], &arr[2]);
	int i;
	float arr2[3];
	float arr3[3];
	for (i = 0; i < 3; i++)
	{
		arr2[i] = (int)(arr[i] * 1000) % 10;
		if (arr2[i] >= 5)
		{
			arr3[i] = ((arr[i] * 1000.0 - arr2[i]) + 10.0) / 1000.0;
		}
		else
		{
			arr3[i] = (arr[i] * 1000.0 - arr2[i]) / 1000.0;
		}
	}

	printf("The each subject score of No. %1d is %.2f, %.2f, %.2f.", a, arr3[0], arr3[1], arr3[2]);
	return 0;
}

//Q5：输出函数的返回值

//描述
//KiKi写了一个输出“Hello world!”的程序，BoBo老师告诉他printf函数有返回值，你能帮他写个程序输出printf(“Hello world!”)的返回值吗？

//int main()
//{
//	int a = printf("Hello world!");
//	printf("\n%d", a);
//	return 0;
//}
//在输出函数返回值的时候，会先执行函数。
