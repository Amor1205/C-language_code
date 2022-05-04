#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>

//int main()
//{
//	if (3 == 5)
//		printf("hehe\n");
//	return 0;
//}
// 
//  单分支
//int main()
//{
//	int a = 10;
//	if (a = 3)
//		printf("hehe\n");
//	return 0;
//}
// 
// 
//双分支
//int main()
//{
//	int age = 10;
//	scanf("%d", &age);
//	if (age > 18)
//		printf("成年\n");
//	else
//		printf("未成年\n");
//	return 0;
//}


//纠错：  不能写连续两个大于 示例
//int main()
//{
//	int age = 10;
//	if (18 <= age < 28)
//		printf("青年\n");    //打印成功
//	return 0;
//}
//int main()
//{
//	int age = 10;
//	if (18 <= age && age < 28)
//		printf("青年\n");  
//	return 0;
//}

//判断一个数是否为奇数
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	if (num % 2 == 1)
//		printf("奇数\n");
//	else
//		printf("偶数\n");
//	return 0;
//}

//输出1 - 100 之间的奇数

//int main()
//{
//	int num = 0;
//	for (num = 0; num < 100; num++)
//	{
//		if (num % 2 == 1)
//			printf("%d\n", num);
//	}
//	return 0;
//}


//switch
//int main()
//{
//	int date;
//	scanf("%d", &date);
//	switch (date)
//	{
//	case 1:
//		printf("星期1\n");
//		break;
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期7\n");
//		break;
//	}
//	return 0;
//}


//输入1-5 输出weekday
//输出6-7 输出weekend

//int main()
//{
//	int d;
//	scanf("%d", &d);
//	switch (d)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("weekday\n");
//			break;
//		case 6:
//		case 7:
//			printf("weekend\n");
//			break;
//		default:
//			printf("错误\n");
//	}
//	return 0;
//}

//while  打印1——10

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d\n", i);
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar())!= EOF)   //getchar() 就是输入一个 整型 （字符也是整型）
//	{                                // =EOF 就是按ctrl + Z 会中止 
//		                             // ！=EOF 就是不等于 EOF 
//		                             // 也就是只要不按Ctrl z 就会一直循环
//		putchar(ch);   //putchar(ch) 就是输出 ch 
//	}
//	return 0;
//}
//
//int ch = 0;
//while ((ch = getchar()!= '\n'))
//{
//	;           //只有一个分号的意思是 执行while 括号内的程序
//}


//密码

//int main()
//{
//	char password[20]= { 0 };
//	printf("请输入密码-->");
//	scanf("%s", password);  //字符串本身就是地址 不用取地址符 用%s打印。
//
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("请确认密码(Y/N):>");
//	int ret = getchar();
//	if ('Y' == ret)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}


//int main()
//{
//	char ch = '\0';
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')  //ch 的ASCII值小于 0 的值 或者 大于9的
//			continue;
//		putchar(ch);
//	}
//	//只打印数字字符
//	return 0;
//}


//写代码将三个整数按从大到小输出。
//例如：
//输入：2 3 1
//输出：3 2 1

//try 1  太繁琐！！！

//#include<stdio.h>
//
//int main()
//{
//	int arr[3];
//	scanf("%d %d %d", &arr[0], &arr[1], &arr[3]);
//	int a = arr[0] > arr[1] ? arr[0] : arr[1];
//	int a1 = arr[0] > arr[1] ? arr[1] : arr[0];
//	//a 是  0 和 1 里较大的,a1是 0 和 1 里较小的，a > a1
//	int b = a > arr[2] ? a : arr[2];
//	int b1 = a > arr[2] ? arr[2] : a;
//	int c = b1 > a1 ? b1 : a1;
//	//b 是 三者最大值, b1是a与 arr[2]较小值
//	printf("%d %d %d",b,c,a)
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if(a>b)
//	{
//		t = a; 
//		a = b;
//		b = t;
//	}
//	if (a > c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b > c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", c,b,a)
//		;	return 0;
//}


//写一个代码打印1-100之间所有3的倍数的数字



//int main()
//{
//	int i = 1;
//	for (i = 1; i < 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}
// 
// 
//给定两个数，求这两个数的最大公约数

//#include<stdio.h>
 //欧几里得算法
//int main()
//{
//	int a, b, t;
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}   //a > b 
//	int i = a % b;
//	while (i>0)
//	{
//		a = b;
//		b = i;
//		i = a % b;
//		printf("%d", b);
//	}
//
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a, b, t;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	while (t = a % b)
//	{
//		a = b;
//		b = t;
//	}
//	printf("%d\n", b);
//	return 0;
//}
//打印闰年 1000 - 2000
//闰年的条件：如果N能够被4整除，并且不能被100整除，则是闰年
//或者：N能被400整除，也是闰年
//即：4年一润并且百年不润，每400年再润一次
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	for (a = 1000; a < 2000; a++)
//	{
//		if (a % 4 == 0)
//		{
//			if (a % 100 != 0)
//			{
//				printf("%d ", a);
//			}
//		}
//		if (a % 400 == 0)
//		{
//			printf("%d ", a);
//		}
//	}
//		
//	return 0;
//}

//打印素数
//#include<stdio.h>
//
//int main()
//{
//	int a, j;
//	int i = 0;
//	for (a = 100; a <= 200; a++)
//	{
//		for (j = 2; j < a; j++)
//		{ 
//			if (a % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == a)
//		{
//			printf("%d ", a);
//			i++;
//		}
//	}
//	printf("\ncount=%d ", i);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int year = 1001;
//	int count = 1;
//	for (year = 1001; year <= 2000; year++)
//	{
//		if (year % 4 == 0)
//		{
//			if (year % 100 != 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//			if (year % 400 == 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//		}
//
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//整数的排序方法，找一个临时变量储存
//比如我要排序a 和 b

//int main()
//{
//	int a, b, t;
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}    // 实现a与b换位。
//	return 0;
//}

//求最大公约数，辗转相除法。
//a%b = t
//a = b   b = t 
//a%b = t
//一直这样循环下去，然后最后t得0 得0得时候的b就是我们要的公约数
