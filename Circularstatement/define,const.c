#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
#define MAX 100
	printf("%d\n", MAX);
	const int a = 10;
	printf("%d\n", a);//const������ǳ���������������int�淶��a��������a�����Ǳ����������г���������
	return 0;
}