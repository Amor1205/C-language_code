#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int x = 0;
	scanf("%d", x);
	int y = 0;
	if (x < 0)
	{
		y = 2 * x - 5;
	}
	else if (x > 2)
	{
		y = -2 * x + 5;
	}
	else
	{
		y = 0;
	}
	printf("%d", y);
	return 0;
}
//2022�����в��ɹ��ġ�
//����	C6066	�����˷�ָ����Ϊ _Param_(2)�����ԡ�scanf���ĵ�����Ҫָ�������ʵ������: ��int����	
//�����˷���ֵscanf