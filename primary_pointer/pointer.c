#define _CRT_SECURE_NO_WARNINGS

//指针是什么
// 1.指针是内存中一个最小单元的编号，也就是地址
//  内存 8G 16G 内存空间如何管理？
//  内存空间的管理：
//  切割成内存单元 - 1byte
//  把内存单元的编号就成为地址
//  地址也叫指针
// 2.平时口头说的指针，一般指指针变量

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	//a 是整型变量，占四个字节的内存空间
//	printf("%p", &a);
//	//a 占四个字节，取地址&a -----> 0056F7B8 是首个单元的地址
//	//不需要每个都存储起来。通过地址就可以找到内存单元
//	int* pa = &a;
//	//pa 是一个指针变量，用来存放地址，但是口头上说指针。
//	//本质上指针就是地址
//	//口语中说的指针一般指指针变量，是一个用来存放地址的变量。
//	return 0;
//}

//32位电脑
//32根地址线
//  00000000 00000000 00000000 00000000
// 2的32次方个可能
// 4GB
// 在32位的机器上，地址是32个0或1组成的二进制序列，那地址就得用4个字节的空间来存储
// 所以一个指针变量的大小就应该是4个字节
// 64位 指针变量的大小 8个字节
//地址是唯一标识一块地址空间的。
//32-4字节，64-8字节
// 
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int* pi = NULL;
//	char* pc = NULL;
//	short* ps = NULL;
//	printf("%d\n", sizeof pi);
//	printf("%d\n", sizeof pc);
//	printf("%d\n", sizeof ps);
//	return 0;
//}
//既然都是4，为什么设置不同的指针变量类型？
// 0 1 2 3 4 5 6 7 8 9 a b c d e f
// 0 
// 1
// 10
// 11
//数字越大，需要的二进制位越多
//10: 1010
//15: 1111
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int a = 0x11223344; // 0x 是 16进制
//	//00010001 00100010 00110011 01000100
//	//int* pa = &a;
//	//*pa = 0;
//	char* pc = (char*)&a;//用char* 代替int*
//	*pc = 0;
//	//发现只改了内存中第一个字节的字符
//	//int*和char*都是四个字节大小，但是决定了返回地址时的访问字节数
//
//	return 0;
//}
//结论
//指针类型决定了指针咋子解引用的时候访问几个字节
//如果是int*的指针，解引用访问4个字节
//如果是char*的指针，解引用访问1个字节
//可以推广到其他类型
//double* --- 8

//注意：相同长度的也不可以混用
//#include<stdio.h>
//int main()
//{
//	int a = 0x0011223344;
//	//100
//	//0x64
//	//不同进制只是表示的形式不同
//	int* pa = &a;
//	char* pc = &a;
//
//	printf("%p\n", pa);//006FFEAC
//	printf("%p\n", pa + 1);//006FFEB0 跳过4个字节，直接访问下一个整型
//
//	printf("%p\n", pc);//006FFEAC
//	printf("%p\n", pc + 1);//006FFEAD 跳过1个字节
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int* pi = &a; // pi 解引用访问4个字节，pi+1也是跳过4个字节
//	float* pf = &a;// pf 解引用访问4个字节，pf+1也是跳过4个字节
//	//int* 和 float* 是不是可以通用？
//	//不能！！！！
//	// *pi = 100;
//	//*pf = 100.0;
//	//规则不一样不能类比
//	return 0;
//}

//3.野指针
//	野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）
//如： 
//int main()
//{
//	int* p; 
//	//p没有初始化，就意味着没有明确的指向
//	//一个局部变量不初始化的话，放的是随机值
//	//
//	*p = 20;//非法访问内存了，因为p没有初始化
//	//如果用p的话，p就是野指针
//	return 0;
//}
// 成因
//1.指针未初始化
//2.指针越界访问

//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;//&arr[0]
//	int i = 0;
//	for (i = 0; i <+ 10; i++)//越界访问了
//	{                        //当指针访问的范围超过可访问的范围，野指针
//		*p = i;
//		p++;
//	}
//	return 0;
//}
//
//int* test()
//{
//	int a = 10; //此时创建a 创建地址
//	return &a;  //放入a的地址
//}
//int main()
//{
//	int* p = test();//a销毁了 p还能找到a的地址，但是a已经找不到了
//	printf("%d\n", *p);//打印出来10，为什么还能找到？
//					   //因为现在内存的这块空间还在，找回去还在
//					   //但不一定一直都在，要求没人占用这块内存
//	//
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;//明确对指针进行初始化
//	//如果出现不知道给他初始化成谁的时候，初始化为NULL 空指针
//	int* p2 = NULL;
//	//用的时候这么用：
//	int* p3 = NULL;
//	if (p3 != NULL)
//	{
//		*p3 = 100;
//	}
//	return 0;
//}

//3.2如何规避野指针
//1.指针初始化
//int* p = &a;
//2.小心指针越界
//3.指针指向空间释放即使指NULL
//4.避免返回局部变量的地址
//5.指针使用之前检查有效性

//4.指针运算
//4.1指针+-整数

//#define N_VALUES 5
//float values[N_VALUES];
//float* vp;
////指针 +- 整数，指针的关系运算
//for (vp = &values[0]; vp < &values[N_VALUES];)//指针比较大小
//	//随着下标的增长，地址由低地址变高地址
//{
//	*vp++ = 0;//*vp = 0； vp++；
//}
// //也可以写成（不推荐）
// //for(vp = &values[N_VALUES-1];vp>=&values[0];vp--)
// //{
// //*vp = 0;
// //}
// //但是！！并不一定全部都成立，标准并不支持
// //因为标准规定：允许指针往后越界，但不允许向前越界。
// 
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int* p = arr;
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	for (; p < &arr[10];p++)
//	{
//		*p = 1;
//	}
//	//也可以写成
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	*(p + i) = 1;
//	//}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//4.2指针-指针
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);
//	//9   
//	//指针-指针（高-低）得到的是之间元素的个数，（低-高是负数）
//	//但不是所有的指针都能相减
//	//只有指向同一块空间的两个指针才可以相减，才有意义。
//	return 0;
//}

#include<stdio.h>
#include<string.h>

//指针的写法
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//指针-指针的方法
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return (str - start);
//}
//int main()
//{
//	int len = my_strlen("abcdefg");
//	printf("%d\n", len);
//	return 0;
//}


//指针能不能相加？指针是地址！地址加地址没有意义。

//数组：一组相同类型元素的集合
//指针变量：是一个变量，存放的是地址。
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//arr首元素地址
//	//&arr[0]
//	int* p = arr;
//	//通过指针来访问数组
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%p ------ %p\n", &arr[i],p + i);
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//		//也可以写成*(arr+i)
//	}
//	return 0;
//}

//二级指针
//示例
//
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int* pa = &a;//pa是一个变量，存放a的地址，是一级指针变量
//	*pa = 20;
//	printf("%d\n", a);
//	printf("%p\n", pa);
//
//	//pa是变量，pa在内存中也有地址，那么可以取pa的地址吗？
//	//
//	int**ppa = &pa;//ppa用来存放一级指针变量的地址，是二级指针
//	//int* 是说明ppa的指向是int*类型， *ppa的*说明ppa是指针
//	printf("%p\n", ppa);
//	printf("%p\n", *ppa);
//	printf("%d\n", **ppa);
//
//	return 0;
//}
//二级指针是用来存放一级指针变量地址的变量
//

//指针数组
//存放指针的数组就是指针数组
//
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;
//	printf("%d\n", a);
//	//如果有太多的数需要取地址定义指针变量
//	//这么写就不方便
//
//	int* parr[10] = { &a,&b,&c };
//	//parr就是存放指针的数组，指针数组
//	*parr[0] = 30;
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", (*parr[i]));
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	//1 2 3 4
//	//2 3 4 5
//	//3 4 5 6
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//模拟二维数组
//#include<stdio.h>
//int main()
//{
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 2,3,4,5 };
//	int arr3[4] = { 3,4,5,6 };
//	int* parr[3] = { arr1,arr2,arr3 };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			//printf("%d ", *(parr[i]+j));
//			printf("%d ", parr[i][j]);
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

