#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
#define MAX 100
	printf("%d\n", MAX);
	const int a = 10;
	printf("%d\n", a);//const定义的是常变量，将本来用int规范的a常量化，a本质是变量，但是有常量的属性
	return 0;
}