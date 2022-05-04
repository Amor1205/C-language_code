#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[] = { 'a','b','c' };
	char arr2[] = { "abc"};
	printf("%d %d\n", strlen(arr1), strlen(arr2));
return 0;
}