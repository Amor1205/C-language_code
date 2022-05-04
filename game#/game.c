#include"game.h"

void Initgraph(char arr[ROW][COL], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void Displaygraph(char arr[ROW][COL], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < y - 1)
				printf("|");
		}
		printf("\n");
		if (i < x - 1)
		{
			for (int  n = 0; n < x; n++)
			{
				printf("---");
				if (n < x - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char arr[ROW][COL], int x, int y)
{
	printf("���������:>\n");
	int a = 0;
	int b = 0;
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a <= x && b <= y && arr[a - 1][b - 1] == ' ')
		{
			arr[a-1][b-1] = '*';
			break;
		}
		else
			printf("\nλ�÷Ƿ�������������:>");
	}
}
void ComMove(char arr[ROW][COL], int x, int y)
{
	printf("��������:>\n");	
	int a, b;

	while (1)
	{
		a = rand() % x;
		b = rand() % y;
		if (arr[a][b] == ' ')
		{
			arr[a][b] = '#';
			break;
		}
	}
}

int even(char board[ROW][COL], int row, int col)//ƽ���ж�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char JudgeWin(char arr[ROW][COL], int x, int y)  //����Ӯ# ���Ӯ* ƽ��Q δ��ʤ��C
{

	/*��
	for (int i = 0; i < x; i++)
	{
		int j = 0;
		while (arr[i][j] == arr[i][j + 1] && (arr[i][j] == '*' || arr[i][j] == '#'))
		{
			j += 1;
			if (j == y)
			{
				return arr[i][j - 1];
			}
		}
	}
	��
	for (int j = 0; j < y; j++)
	{
		int i = 0;
		while (arr[i][j] == arr[i+1][j] && (arr[i][j] == '*' || arr[i][j] == '#'))
		{
			i += 1;
			if (i == x)
			{
				return arr[i-1][j];
			}
		}
	}
	�Խ�
	for (int i = 0; i < x; i++)
	{
		int j = y-1;
		while (arr[i][j] == arr[i + 1][j - 1] && (arr[i][j] == '*' || arr[i][j] == '#'))
		{
			j -= 1;
			i += 1;
			if (j == -1)
			{
				return arr[i - 1][j + 1];
			}
		}
		i = 0;
		j = 0;
		while (arr[i][j] == arr[i + 1][j + 1] && (arr[i][j] == '*' || arr[i][j] == '#'))
		{
			i += 1;
			j += 1;
			if (j == y)
			{
				return arr[i - 1][j - 1];
			}
		}
	}*/
	int i = 0;
	//judge row
	for (i = 0; i < x; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
			return arr[i][1];//ֱ�ӷ������е��ַ�����������ж�
	}
	//judge col
	for (i = 0; i < y; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
			return arr[1][i];
	}
	//judge dia
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	//��ƽ�ͼ���
	for (int i = 0; i < x; i++)
	{
		for (int n = 0; n < y; n++)
		{
			if (arr[i][n] == ' ')
				return 'C';
		}
	}
	return 'Q';
}
void game()
{
	char ret = 0;
	char graph[ROW][COL] = { 0 };   //����game�����ڲ�����
	Initgraph(graph,ROW,COL);
	Displaygraph(graph, ROW, COL);

	if (ret != 'C')
	{
		while (1)
		{
			PlayerMove(graph, ROW, COL);
			Displaygraph(graph, ROW, COL);
			ret = JudgeWin(graph, ROW, COL);
			if (ret != 'C')
				break;
			ComMove(graph, ROW, COL);
			Displaygraph(graph, ROW, COL);
			ret = JudgeWin(graph, ROW, COL);
			if (ret != 'C')
				break;
		}
	}
	if (ret != 'C')
	{
		if (ret == '*')
		{
			printf("���ʤ��\n");
			printf("\n");
		}
		else if (ret == '#')
		{
			printf("����ʤ��\n");
			printf("\n");
		}
		else if (ret == 'E')
		{
			printf("ƽ�֣�\n");
			printf("\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������(1/0):>\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			//��������Ϸ
			game();
			break;
		case 0:
			printf("��Ϸ������\n");
			printf("������˳���Ϸ\n");
			Sleep(3000);
			break;
		default:
			printf("�������\n");
			printf("����������\n");
			break;
		}
	} while (input);
	return 0;
}