#define _CRT_SECURE_NO_WARNINGS

//�������ʽ��(-8 + 22)��a - 10 + c��2�������У�a = 40��c = 212��
//
//����������
//�ޡ�
//���������
//(-8 + 22)��a - 10 + c��2����֮��Ľ����Ϊһ��������

#include<stdio.h>
int main()
{
	int a = 0;
	int c = 212;
	int b = (-8 + 22) * a - 10 + c / 2;
		printf("%d", b);
return 0;
}