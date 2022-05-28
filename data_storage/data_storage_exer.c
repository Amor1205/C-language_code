#define _CRT_SECURE_NO_WARNINGS

//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
//
//数据范围：1≤n, m≤1000  ， 序列中的值满足 0≤val≤30000
//输入描述：
//输入包含三行，
//
//第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。
//
//第二行包含n个整数，用空格分隔。
//
//第三行包含m个整数，用空格分隔。
//输出描述：
//输出为一行，输出长度为n + m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。
//void sort(int*arr, const int x)
//{
//	for (int i = 0; i < x-1; i++)
//	{//右移操作
//		for (int j = 0; j < x - i ; j++)     
//		{
//			int temp = 0;
//			if (*(arr + i) > *(arr + j + i))
//			{
//				temp = *(arr + j + i);
//				*(arr + i + j) = *(arr + i);
//				*(arr + i) = temp;
//
//			}
//		}
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	int arr3[2000] = { 0 };
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	//排序
//	sort(arr1, n);
//	sort(arr2, m);
//	//合并
//	for (int i = 0; i < n + m; i++)
//	{
//		if (i < n)
//		{
//			arr3[i] = arr1[i];
//		}
//		else
//		{
//			arr3[i] = arr2[i - n];
//		}
//	}
//	//排序
//	sort(arr3, n + m);
//	//打印
//	for (int i = 0; i < n + m; i++)
//	{
//		printf("%d ", arr3[i]);
//	}
//	return 0;
//}


//做法可行但是，占用内存较大，运行时间较长
//考虑可以只写一个数组

//void sort(int* arr, const int x)
//{
//	for (int i = 0; i < x - 1; i++)
//	{//右移操作
//		for (int j = 0; j < x - i; j++)
//		{
//			int temp = 0;
//			if (*(arr + i) > *(arr + j + i))
//			{
//				temp = *(arr + j + i);
//				*(arr + i + j) = *(arr + i);
//				*(arr + i) = temp;
//
//			}
//		}
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int arr[2000] = { 0 };
//
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &arr[n+i]);
//	}
//	//排序
//	sort(arr, n+m);
//	//打印
//	for (int i = 0; i < n + m; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//描述
//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。
//
//输入描述：
//输入包含一个整数n(0 ≤ n ≤ 109)
//
//输出描述：
//输出一个整数，即小乐乐修改后得到的数字。

//取余
////#include<stdio.h>
////int judge_odd(int n)
////{
////	return n % 2;
////}
////int take_out(int n,int x)
////{
////	int div = 10;
////	for (int i = 0; i < x; i++)
////	{
////		div *= 10;
////	}
////	return ((n % div) - (n % (div / 10))) / (div / 10);
////}
////int judge_pos(int num)
////{
////	int div = 10;
////	int pos = 1;
////	while (1)
////	{
////		if (num % div != num && num != div)
////		{
////			div *= 10;
////			pos++;
////		}
////		else if (num == div)
////		{
////			return pos + 1;
////		}
////		else
////			return pos;
////	}
////}
////int main()
////{
////	int num = 0;
////	int div = 10;
////	//抽出位数
////	//判断奇偶
////	int f = 0;
////	int pos = judge_pos(num);
////	scanf("%d", &num);
////	for (int i = 0; i < pos; i++)
////	{
////		f += (judge_odd(take_out(num, i)) * (div / 10));
////	}
////	printf("%d", f);
////	return 0;
////}

//上面这个一直运行不好！！

//新的方法
//#include<stdio.h>
//int Digit(int n)
//{
//	int i = 10;
//	int count = 1;
//	while (n / i > 0)
//	{
//		count++;
//		i *= 10;
//	}
//	return count;
//}
//int main()
//{	
//	int n = 0;
//	scanf("%d", &n);
//	int dig = Digit(n);
//	int a[10] = { 0 };
//	int m = n;
//	int div = 1;
//	for (int i = 0; i < dig; i++)
//	{
//		a[i] = m % 10;
//		m = (m - m % 10) / 10;
//	}
//	int sum = 0;
//	for (int j = 0; j < dig; j++)
//	{
//		sum += (a[j] % 2) * div;
//		div *= 10;
//	}
//	printf("%d", sum);
//	return 0;
//}

//KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的带空格直角三角形图案。
//
//输入描述：
//多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“ * ”的数量，也表示输出行数。
//
//输出描述：
//针对每行输入，输出用“ * ”组成的对应长度的直角三角形，每个“ * ”后面有一个空格。

//#include<stdio.h>
//#include<assert.h>
//int main()
//{
//	int n = 2;
//	assert(n >= 2 && n <= 20);
//	while (scanf("%d", &n) != EOF)
//	{
//		char arr[40] = { 0 };
//		// 5   5 * 2 - 1
//		for (int i = n; i > 0; i--)
//		{
//			arr[i * 2 - 2] = '*';
//			for (int j = 0; j <= (2 * n + 1); j++)
//			{
//				printf("%c", arr[j]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//可以输出但是在牛客网上面输出不了？？？不知道为什么
//换一种方法吧。

//#include<stdio.h>
//int main() 
//{
//	int a;
//	while (scanf("%d", &a) != EOF) 
//	{
//		int i, k;
//		for (k = 0; k < a; k++) 
//		{
//			for (i = 0; i < (a - k - 1); i++)
//			{
//				printf("  ");
//			}
//			for (i = 0; i <= k; i++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	while(scanf("%d", &a)!=EOF)
//	{
//		for (int i = 0; i < a; i++)
//		{
//			for (int j = 0; j < (a - i - 1); j++)
//			{
//				printf("  ");
//			}
//			for (int j = 0; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//描述
//KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，如果今天是“双11”（11月11日）则这件衣服打7折，“双12” （12月12日）则这件衣服打8折，如果有优惠券可以额外减50元（优惠券只能在双11或双12使用），求KiKi最终所花的钱数。
//
//数据范围：衣服价格满足1≤val≤100000
//输入描述：
//一行，四个数字，第一个数表示小明看中的衣服价格，第二和第三个整数分别表示当天的月份、当天的日期、第四个整数表示是否有优惠券（有优惠券用1表示，无优惠券用0表示）。 注：输入日期保证只有“双11”和“双12”。
//输出描述：
//一行，小明实际花的钱数（保留两位小数）。（提示：不要指望商家倒找你钱）

//#include<stdio.h>
//int main()
//{
//	float val = 0.0;
//	float real_val = 0.0;
//	int mon = 0;
//	int date = 0;
//	int j = 0;
//
//	scanf("%f %d %d %d", &val, &mon, &date, &j);
//	//判断月份
//	if (11 == mon && 11 == date)
//	{
//		if (1 == j)
//			real_val = val * 0.7f - 50.0;
//		else
//			real_val = val * 0.7f;
//	}
//	else if (12 == mon && 12 == date)
//	{
//		if (1 == j)
//			real_val = val * 0.8f - 50.0;
//		else
//			real_val = val * 0.8f;
//	}
//	else
//		real_val = val;
//	if (real_val < 0.0f)
//		real_val = 0.0f;
//	printf("%.2f", real_val);
//	return 0;
//}
//程序执行的结果
//#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	//128+64    1100 1000
//	unsigned char b = 100;
//	// 64+32+4    0110 0100
//	//a+b 需要提升至int
//	// 上限不再为255 而是 32767
//	unsigned char c = 0;
//	
//	//c = a + b
//	//1100 1000
//	//0110 0100
//	//0010 1100
//	//32+8+4 = 44  	c = a + b;
//
//	printf(" %d %d", a + b, c);
//	return 0;
//}

//unsigned int a = 0x1234;  //16进制
////1 2 3 4 
////0000 0000 0000 0000 0001 0010 0011 0100 
//unsigned char b = *(unsigned char*)&a;


//下面代码的结果是（ ）
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    // -1 -2 -3 -4 -5 -6 .... -128 127 126 125
//    printf("%d", strlen(a));
//    return 0;
//}


//猜名次
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//
//A选手说：B第二，我第三；
//
//B选手说：我第二，E第四；
//
//C选手说：我第一，D第二；
//
//D选手说：C最后，我第三；
//
//E选手说：我第四，A第一；
//
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。



#include <stdio.h>

//int checkData(int* p)
//{
//	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。
//
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
//		{
//			return 0;
//		}
//		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
//	}
//	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
//}
//
//int main()
//{
//	int p[5]; //0 1 2 3 4分别代表a b c d e
//
//	for (p[0] = 1; p[0] <= 5; p[0]++)
//	{
//		for (p[1] = 1; p[1] <= 5; p[1]++)
//		{
//			for (p[2] = 1; p[2] <= 5; p[2]++)
//			{
//				for (p[3] = 1; p[3] <= 5; p[3]++)
//				{
//					for (p[4] = 1; p[4] <= 5; p[4]++) //五层循环遍历
//					{
//						//这里是五个人的描述，由于比较表达式只有0和1两个结果，如果要两个条件有且只有一个为真，则可以用比较表达式的值总和为1的方式直接判定。别忘了还要判定不能并列。
//						if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//							(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//							(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//							(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//							(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
//							checkData(p) //不能并列
//							)
//						{
//							for (int i = 0; i < 5; i++)
//							{
//								printf("%d ", p[i]);
//							}
//							putchar('\n');
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//#include<stdio.h>
//int checkData(const a[4])
//{
//	if ((a[0] + a[1] + a[2] + a[3]) == 1)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a[4] = { 0 };
//	for (a[0] = 0; a[0] <= 1; a[0]++)
//	{
//		for (a[1] = 0; a[1] <= 1; a[1]++)
//		{
//			for (a[2] = 0; a[2] <= 1; a[2]++)
//			{
//				for (a[3] = 0; a[3] <= 1; a[3]++)
//				{
//					if ((a[0] != 1) + (a[2] == 1) + (a[3] == 1) + (a[3] != 1) == 3 && checkData)
//					{
//						if (a[0])
//							printf("A是凶手\n");
//						else if (a[1])
//							printf("B是凶手\n");
//						else if(a[2])
//							printf("C是凶手\n");
//						else
//							printf("D是凶手\n");
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//上面是自己的做法 发现不对
//输出有错误

//#include<stdio.h>
//int main()
//{
//    int killer = 0;
//    //分别假设凶手是a,b,c,d,看谁是凶手时满足3个人说了真话，一个人说了假话
//    for (killer = 'a'; killer <= 'd'; killer++)
//    {
//        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//            printf("凶手是：%c", killer);
//    }
//    return 0;
//}

//打印杨辉三角

#include<stdio.h>
int main()
{
	int arr[30][30] = { 0 };
	int n = 10;
	for (int i = 1; i < n; i++)
	{
		arr[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]!= 0)
			{
				printf("%d  ", arr[i][j]);
			}
		}
		printf("\n");	
	}
	return 0;
}