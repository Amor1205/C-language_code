#define _CRT_SECURE_NO_WARNINGS
//写一个函数求两个整数的较大值
//如：
//输入：10 20
//输出较大值：20
#include<stdio.h>

//写法1

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		return c = a;
//	}
//	else
//	{
//		return c = b;
//	}
//	printf("%d", c);
//	return 0;
//}

int main()
{

	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	if(a>b)
	{
		printf("%d", a);
	}
	else
	{
		printf("%d", b);
	}
	return 0;
}