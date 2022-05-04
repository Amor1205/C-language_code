#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
//{
//	int a = 0;
//		if (!a)
//		{
//			printf("hehe\n");
//		}
//			return 0;

//}  
	// 结果：打印出hehe，如果是 a = 1 则打印不出
	// ！ 的意思是 反值 ，真则为假 假则为真。

//{
//	int a = 0;
//	printf("%d\n",sizeof(a));    // 4
//	printf("%d\n", sizeof(int)); // 4
//	printf("%d\n", sizeof a);    // 4
//	printf("%d\n", sizeof int);  //错误
//
//
//		return 0;
//}

//{
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof arr);   //40  10个元素 每个元素是一个整型，每个整型4个字节。
//	printf("%d\n", sizeof(arr[0]));   //4  数组里的第一个元素大小
//	printf("%d\n", sizeof(arr)/sizeof(arr[0])); //10 
//	return 0;
//}

//{
//	int a = 10;
//	int b = a++;
//	printf("%d\n", a);   //11
//	printf("%d\n", b);   //10
//
//	return 0;
//}
//{
//	int a = 10;
//	int b = ++a;
//	printf("%d\n", a);    //11
//	printf("%d\n", b);    //11
//
//	return 0;
//}

//{
//	//int a = 3.14;
//	int a = (int)3.14;  //括号括起来时想要他成为的类型
//	// 3.14 字面浮点数，编译器默认理解为double类型
//	printf("%d\n", a);
//	return 0;
//}

//{
//	int a = 10;
//	if (a = 3)
//	{
//		printf("hehe\n");
//	}
//}

//{
//	int a = 10;
//	if (a == 3)
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}

//{
//	int a = 10;
//	int b = 0;
//	if (a && b)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//{
//	int a = 10;
//	int b = 20;
//	int r = a > b ? a : b;  //因为a > b 为假，所以后面的算。输出b
//	printf("%d\n", r); //20
//	return 0;
//}

//{
//	int a = 10;
//	int b = 20;
//	int c = 5;
//	
//	int d = (c = a - 2, b = c + 1, c - 3);
//	printf("%d\n", d);
//	return 0;
//}

//{
//int arr[5] = { 1,2,3,4,5 };
//int n = 3;
//arr[n] = 20;
//printf("%d\n", arr[n]);
//
//	return 0;
//}