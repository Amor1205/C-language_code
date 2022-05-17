#define _CRT_SECURE_NO_WARNINGS
//
//调试
//调试 Debugging 又称除错
//是发现和减少计算机程序或电子仪器设备中程序错误的一个过程

//基本步骤
//
//发现程序错误的存在
//以隔离、消除等方式对错误进行定位
//确定错误产生的原因
//提出纠正错误的解决办法
//对程序错误予以改正，重新测试
//
//Debug 与 Release
//Debug: 调试版本。包含调试信息，并且不做任何优化，便于程序员调试程序
//Release: 发布版本。往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好的使用。
//由于Debug版本含有调试信息，并且未做优化，所以所占内存较大。
// 
// 基于VS2019版本进行调试，但是不管什么环境，都可以进行调试的
// 
// 3.1调试环境的准备: 确保是Debug版本。
// 3.2学会相关的快捷键
// F5: 启动调试，如果在代码走的过程中没有任何一个断点拦截调试，会自动进行直至完结
// F9: 创建断点和取消断点
// 断点: 
// 如果前面的代码没有问题，我们可以在没问题的代码之后设置断点(F9)，按F5可以跳过这一部分
// 
// F10: 逐过程，跳过一条语句(可以是函数调用或者是一条语句)
// F11: 逐语句，进入函数内部
//有的电脑支持取消FN 有的不支持
// 
// 3.3调试的时候查看程序当前信息
//  F10 调试开始后，窗口启动监视
//监视时如果是数组，可以加arr,10可以直接查看每个元素
//也可以查看内存，列，1行显示几列，一般显示四列，
// 一列表示一个字节的数据，显示时以16进制显示
// 调用堆栈，是从下往上读，反应函数的调用逻辑
// 
//
//
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}
//越界了，数组下标，向上越界
//


//栈区内存的使用习惯是: 先使用高地址空间，在使用低地址空间
//数组随着下标的增长，地址是由低到高变化的。
//如果i和arr之间有合适的空间，利用数组的越界操作就可能覆盖到i，就可能导致死循环出现


//优秀代码
//代码运行正常
//bug少
//效率高
// 可读性好
// 注释清晰
// 可维护性高
// 文档齐全
//

//coding技巧
//
// 用assert
// 尽量使用const
// 良好的编码风格
// 添加必要注释
// 
//

//strcpy
// arr2放到arr1中去
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void my_strcpy1(char*pa1, char*pa2)
//{
//	while (*pa2 != '\0')
//	{
//		*pa1 = *pa2;
//		pa1++;
//		pa2++;
//	}
//	*pa1 = *pa2; // '\0'赋值给arr1
//}
////但是这并不是最优质写法！
//
// 为什么返回char*
// 是为了实现链式访问
// strcpy函数返回的是目标空间的起始地址
//char* my_strcpy2(char* dest, const char* src)//将src写const，不会改变*src的值
//{
//	//判断scr是否为空指针
//	assert(src != NULL);
//	assert(dest != NULL);
//  char*ret = dest;
//  //进入就保存返回值
//	//把输入空指针的风险被扼杀在摇篮里，断言assert
//	//如果
//	while (*dest++ = *src++);
// return ret;
//}
//int main()
//{
//	//char arr1[20] = { 0 };
//	char arr1[20] = "xxxxxxxxxxxxxxxxxxx";
//
//	char arr2[] = "hello bit!";
//	//strcpy 再拷贝字符串的时候，会把原字符串的\0拷贝过去
//	//strcpy(arr1, arr2);
//	my_strcpy2(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	const int num = 10;
//
//	//num = 20;	//会报错，左值为const对象，就不会被修改
//	int* p = &num;
//
//	*p = 20;//绕过const这层逻辑，用指针可以修改
//	//const 还可以修饰指针变量
//	// 放在*的左边
//	//也可以const 放在int右边，意思一样
//	//意思是：p指向的对象不能通过p来改变了。但p变量本身得知是可以改变的。
//	const int* p = &num;
//	//const也可以放在*的右边
//	//意思是p指向的对象是可以通过p来改变的，但是不能修改p变量本身的值
//	int* const p = &num;
//	//如果*左，*右都带上const 就都不能被改变了。
//
//	printf("%d", num);
//
//	return 0;
//}

//Example
//#include<stdio.h>
//int main()
//{
//	int m = 10;//男m
//	int n = 100;//男n
//	//int* p = &m;//女p，和m恋爱
//	//女让男m请吃饭，男m只剩十块钱，吃完就没钱了。
//	//男孩让改
//	//const int* p = &m;
//	//p = &n;//女换男朋友n
//	//男m说不行
//	//int* const p = &m;
//	//*p = 0;//OK
//	//p = &n; err
//	const int* const p = &m;
//	//*p = 0;//OK
//	//p = &n;//err
//	return 0;
//}
//
//#include<stdio.h>
//
//int my_strlen(char*p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//		return count;
//}
//int main()
//{
//	int len = strlen("djadakwjdk");
//	int len2 = my_strlen("djadakwjdk");
//	printf("%d\n", len);
//	printf("%d\n", len2);
//	return 0;
//}

//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

#include<stdio.h>
int Judge_odd(int* p)
{
	if (1 == *p % 2)
		return 1;
	else
		return 0;
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr_odd[10] = { 0 };
	int arr_even[10] = { 0 };
	int num_odd = 0;
	int num_even = 0;
	for (int i = 0; i < 10; i++)
	{
		if (1 == Judge_odd(arr + i))
		{
			arr_odd[num_odd] = arr[i];
			num_odd++;
		}
		else
		{
			arr_even[num_even] = arr[i];
			num_even++;
		}
	}
	for (int i = 0; i < num_odd; i++)
	{
		arr[i] = arr_odd[i];
	}
	for (int i = 0; i < num_even; i++)
	{
		arr[i + num_odd] = arr_even[i];
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);

	}
	return 0;
}