#define _CRT_SECURE_NO_WARNINGS
int MAX(int x, int y)    //我又写了一个函数，int max这个函数，所以后面应该有大括号
{
	if (x > y)
		// if return掉， 
		return x;

	else

		return y;
}
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n",MAX(a, b));
	return 0;
}