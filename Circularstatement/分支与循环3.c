#define _CRT_SECURE_NO_WARNINGS

//二分比较 折半查找（有序数组）
// left 作为左下标，right 作为右下标，mid作为中间元素下标
// 比较 input 和 mid元素的大小，
// 缩小范围  若input 大 左下标 变成 mid + 1 
//           若input 小 右下标 变成 mid - 1
// 
// 

//#include<stdio.h>
//
//int main()
//{
//	int arr[10]= { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("%d ", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("找不到\n");
//	return 0;
//}


//自己写的:
// 
//#include<stdio.h>
//
//int main()
//{
//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int r = sz - 1;
//	int right = r;
//	int input = 11 ;
//	int mid = (left + right) / 2;         // ( left + right )/2 可能加起来超过整型的最大值
//	int i;                                // 如果定义 left + (right - left)/2  不会越界
//	int flag = 0;                         // 不能分别除以二相加，整型只能除一次。
//	while (0 == flag)
//	{
//		if (input == arr[mid])
//		{
//			flag = 1;
//			printf("%d\n",mid);
//			break;
//		}
//		else if (input > arr[mid])
//		{
//			left = mid;
//			mid = (left + right) / 2;
//		}
//		else
//		{
//			right = mid;
//			mid = (left + right) / 2;
//		}
//		if (mid == left)
//			break;
//	}
//	if (0 == flag)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}
// 
//字符跳跃


//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "hello world!!!!!";                     //字符数组 和 整型数组的区别
//	char arr2[] = "################";                     //字符数组求元素个数用 sz - 2（需要减一个\0）或者 strlen - 1
//											              //整型数组求元素个数用 sz - 1
//	int r = strlen(arr1) - 1 ;
//	int l = 0;
//	while(l<=r+1)
//	{
//
//		printf("%s\n", arr2);
//		arr2[r] = arr1[r];
//		arr2[l] = arr1[l];
//		l++;
//		r--;
//		Sleep(1000);                     //Sleep(1000) 休眠1000ms   用windows.h 头文件
//		system("cls");                   //system库函数  cls---清屏 用stdlib.h 头文件 
//	}
//	
//
//	return 0;
//}
//编写代码实现登录情景

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20];
//	int flag = 0;
//	//假设密码是字符串：abcdef
//	for (i = 0; i < 3; i++)
//	{
//		printf("\n请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password,"abcdef") == 0)    //字符数组和字符数组或者字符串比较是用strcmp
//	    										//头文件是string.h
//		{
//			printf("\n登陆成功");
//			flag = 1;
//			break;
//		}
//		else
//			printf("\n登陆失败，请重新输入密码");
//	}
//	if (flag = 0)
//		printf("登陆失败");
//	return 0;
//}

//电脑产生一个随机数（1-100）
//猜数字 大了说猜大了，小了说猜小了

//随机数关键点：
// 时间戳的使用：用time头文件，如果用时间戳的话，需要(unsigned int)time(NULL)  前面是强制转换成int类型 因为time函数返回值是time_t
// 随机数的取用：用stdlib头文件，rand(),srand()，其中为了让srand中间的数一直变化用时间戳，srand((unsigned int)time(NULL))
// do while(input)的巧妙使用： input 只能输入 0 和 1， 0的时候循环结束，游戏结束
// 复杂的代码需要先写主题再写枝干

//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("**************************\n");
//	printf("********* 1. play ********\n");
//	printf("********* 0. exit ********\n");
//	printf("**************************\n");
//}
//void game()
//{
//	//1.生成随机数
//	//2.猜数字
//	int r = rand();//生成随机数的函数   范围： 0 - RAND_MAX （32767）
//	                 //用rand 先用srand    
//					 //用<stdlib.h>
//	int ret = r % 100 + 1;
//	printf("%d\n", ret);
//	int guess;
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));  //因为time函数返回值是time_t类型的 需要用unsigned int强制转换
//	do
//	{
//		menu();
//		printf("请选择:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("猜数字\n");
//			game();
//			
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择！\n");
//			break;
//		}
//	}
//	while (input);
//	return 0;
//}


//时间戳：每分每秒都在发生变化的数值
//如何调用时间戳？
//time(NULL --- 空指针)  返回值是 time_t
//我们把他强制转化为unsigned int类型就可以用随机值了
//调用time.h头文件


//随机数生成   
//srand((unsigned int)time(NULL));  一次程序中只需要调用一次，故放在主函数中
//int ret = rand();
//NULL空指针 意思是不用这个值 (define NULL = 0)
//  如何让随机数确定范围？
//  想得到0-100的数字 rand % 100 + 1 就是 1- 100的数字


//电脑关机：
//system(shutdown -s -t 60)  
//停止关机shutdown -a

//演示goto

//#include<stdio.h>
//#include<string.h>

//int main()
//{
//	char input[20] = { 0 };
//again:
//	system("shutdown -s -t 60");
//	printf("在60s后关机，输入我是猪\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//如果不用goto，也是可以写很好的代码。

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		printf("在60s后关机，输入我是猪\n");
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			printf("取消关机\n");
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

#include<stdio.h>

#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu()
{
	printf("*****************************\n");
	printf("********** 1.play ***********\n");
	printf("********** 0.exit ***********\n");
	printf("*****************************\n");
}
void game()
{
	int rad = rand();
	int r = rad % 100 + 1;
	int guess;
	while (1)
	{
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜小了！\n");
			printf("请重新输入:>");
		}
		else if (guess > r)
		{
			printf("猜大了！\n");
			printf("请重新输入:>");
		}
		else
		{
			printf("猜对了！\n");
			break;
		}
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("开始游戏?(1/0):>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束！\n");
			break;
		default:
			printf("输入错误，请重新输入:>");
			break;
		}
	} while (input);
	return 0;
}