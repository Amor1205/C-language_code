#define _CRT_SECURE_NO_WARNINGS
//дһ�����������������Ľϴ�ֵ
//�磺
//���룺10 20
//����ϴ�ֵ��20
#include<stdio.h>

//д��1

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		return c = a;
//	}
//	else
//	{
//		return c = b;
//	}
//	printf("%d", c);
//	return 0;
//}

int main()
{

	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	if(a>b)
	{
		printf("%d", a);
	}
	else
	{
		printf("%d", b);
	}
	return 0;
}