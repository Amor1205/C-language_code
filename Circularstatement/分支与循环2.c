#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>

//while循环
//
//int main()
//{
//	int i = 0;  //初始化部分
//	while (i < 10) //判断部分
//	{
//		printf("%d ", i);
//		i += 2;  //调整部分
//	}
//	return 0;
//}

//int main()
//{
//	int i;
//	for (i = 0; i < 10; i += 2)
//	{
//		if (i == 6)
//			break;
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//0-9
//	int i = 0;
//	for (i = 0; i < 10; i++)  //最好用 = 0 前闭 < 10  后开 写法
// 	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	for (;;)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int j = 0;
//	int z = 0;
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//			z++;
//		}
//
//	}
//	printf("%d", z);
//	return 0;
//}

//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//笔试题
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0, j = 0; j = 3; i++, j++)
//	{
//		printf("hehe\n");
//		j++;
//	}
//	return 0;
//}


// do while
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	while (i<10);
//	return 0;
//}

//计算n的阶乘
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int i;
//	int f = 1;
//	scanf("%d", &n);
//	for (i = 1; i < n + 1; i++)
//	{
//		f = i * f;
//	}
//	printf("%d", f);
//	return 0;
//}
//计算1！+2！+ ....10!

#include<stdio.h>

//int main()
//{
//	int n, i;
//
//	int f2 = 0;
//	for (n = 1; n < 4; n++)
//	{
//		int f1 = 1;
//		for (i = 1; i < n + 1; i++)
//		{
//			f1 = i * f1;
//		}
//		f2 = f2 + f1;
//	}
//	printf("%d", f2);
//	return 0;
//}

//优化一下
//int main()
//{
//	int n, i;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n < 4; n++)
//	{
//		ret *= n;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}
//在一个有序数组中查找具体的某个数字n。
//编写int binsearch(int x,inv[],int n);
//功能：在v[0]<=v[1]<=v[2]....<=v[n-1]的数组中查找x

//#include<stdio.h>
//
//int binsearch(int x, int v[], int n)
//{
//	int sz = sizeof(v[]) / sizeof(v[0]);
//	for (n = 0; n < sz; n++)
//	{
//		if (x == v[n])
//		{
//			printf("x=v[%d]", n);
//			break;
//		}
//	}
//}
//int main()
//{
//	int v[];
//	int x;
//	int n;
//	scanf("")
//	return 0;
//}

//?????


//编写程序数一下 1到 100 的所有整数中出现多少个数字9


//int main()
//{
//	int a;
//	int count = 0;
//	for (a = 1; a < 101; a++)
//	{
//		if (a % 10 == 9 || ((a - 90) >= 0 && (a - 90) < 10))
//			count++;
//	}
//	printf("count=%d", count);
//	return 0;
//}
//算 1/1 - 1/2 + 1/3 - 1/4 ..... + 1/100 = ？
//#include<stdio.h>
//
//int main()
//{
//	float i = 1.0;
//	float sum = 0.0;
//	float a = 1.0;
//	float flag = 1.0;
//	for (i = 1.0; i <= 100.0; i++)
//	{
//		a =	(flag / i);
//		sum += a;
//		flag *= -1;
//	}
//	printf("%.2f", sum);
//	return 0;
//}

//十个数里找最大值
//#include<stdio.h>
//int max(int x, int y)
//{
//	if (x < y)
//		return y;
//	else
//		return x;
//}
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int m = arr[0];
//	for (i = 0; i < 9; i++)
//	{
//		m = max(m, arr[i + 1]);
//	}
//	printf("%d", m);
//	return 0;
//}


//输出乘法口诀表
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	int j = 1;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j < i + 1; j++)
//		{
//			printf("%d * %d = %d  ", j, i, i*j);
//		}
//		printf("\n");
//	}
//	return 0; 
//}

#include<stdio.h>

int main()
{
	int arr[10]={1,3,4,5,7,8,9,10,11,19};
	int x = 11;
	int i = 0;
	int flag = 0;
	for (i = 0; i < 10; i++)
	{
		if (x == arr[i])
		{
			printf("%d", i);
			flag = 1;
			break;
		}
	}
	if (0 == flag)
	{
		printf("找不到\n");
	}
	return 0;
}