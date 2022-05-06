#include"game.h"
#define _CRT_SECURE_NO_WARNINGS

void InitBoard(char arr[ROWS][COLS], int x, int y,char set)
{
	for (int i = 0; i <= x ; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			arr[i][j] = set;
		}
	}

}
void DisplayBoard(char arr[ROWS][COLS], int x, int y)
{
	printf("----------GAME ZONE----------\n");
	printf(" ");
	for (int j = 1; j <= y; j++)
	{

		printf(" %d ", j);
	}
	printf("\n");
	for (int i = 1; i <= x; i++)
	{
		printf("%d", i);
		for (int j = 1; j <= y; j++)
		{
			printf(" %c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("----------GAME ZONE----------\n");
}
void Setboom(char arr[ROWS][COLS], int x, int y,int num)
{
	// 1 - 9 ������ �������
	// �����ظ�������һ��λ��
	int ret = 0;
	while(ret < num)
	{
		int a = rand() % x + 1;
		int b = rand() % y + 1;
		if (arr[a][b] != '1')
		{
			arr[a][b] = '1';
			ret++;
		}
	}
}
char NUM(char arr[ROWS][COLS],int a, int b)
{
	char first = '0';
	char num = '0';
	for (int x = a - 1; x <= a + 1; x++)
	{
		for (int y = b - 1; y <= b + 1; y++)
		{
			if (arr[x][y] == '1')
			{
				num = first + 1;
				first = num;
			}
		}
	}
	return num;
}
//void Checkboom(char arr1[ROWS][COLS],char arr2[ROWS][COLS] ,int x,int y)
//{
//		int a = 0;
//		int b = 0;
//		printf("Please choose an address to check:>");
//		scanf_s("%d %d", &a, &b);
//		//Ҫ����1-9�����֣�����Խ��
//		if (a <= x && a > 0 && b <= y && b > 0)
//		{
//			//ը����ը
//			if (arr1[a][b] == '1')
//			{
//				printf("BOOM! GAME OVER!\n");
//				//������Ϸ��������δ���ú�
//			}
//			//���һ���м���ը��
//			else
//			{
//				char num = NUM(arr1,a, b);
//				arr2[a][b] = num;
//				//���ô�ӡһ��show
//			}
//
//		}
//		else
//			printf("unknown address,please input again!\n");
//}

int Checkboom(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
{
	int a = 0;
	int b = 0;
	int ret = 0;
	while (1)
	{
		printf("Please choose an address to check:>");
		scanf_s("%d %d", &a, &b);
		if (arr2[a][b] != '*')
			printf("You have checked this address,please input again!\n");
		else
		{
			if (a <= x && a > 0 && b <= y && b > 0)
			{
				//ը����ը
				if (arr1[a][b] == '1')
				{
					ret = 1;
					return ret;
					//������Ϸ��������δ���ú�
				}
				//���һ���м���ը��
				else
				{
					char num = NUM(arr1, a, b);
					arr2[a][b] = num;
					//���ô�ӡһ��show
					break;
				}
			}
			else
				printf("unknown address,please input again!\n");
		}
	}
	
	return 0;
}