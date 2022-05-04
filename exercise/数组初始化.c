#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
int main()
{
	int arr1[10] = { 1 };
	printf("%d\n", sizeof(arr1));
	int arr2[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int arr3[10] = { 1,2,3,4,5,6,7,8,9,0 };

	printf("%zu\n", sizeof(arr2));
	printf("%zu\n", sizeof(arr3));


	return 0;
}