#define _CRT_SECURE_NO_WARNINGS
int MAX(int x, int y)    //����д��һ��������int max������������Ժ���Ӧ���д�����
{
	if (x > y)
		// if return���� 
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