#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("******** 1.play ***********\n");
	printf("******** 0.exit ***********\n");
	printf("***************************\n");
}

game()
{
	//ѡ����Ϸ�Ѷ�
	//choose_dif();
	char mine[ROWS][COLS] = { 0 };// = { '0' }���󣬲���ȫ��ʼ��//��Ų����׵���Ϣ
	char show[ROWS][COLS] = { 0 };// = { '*' };//����Ų��׵���Ϣ
	//��ʼ����������Ϊָ��������
	InitBoard(mine, ROW, COL,'0');
	InitBoard(show, ROW, COL,'*');
	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);
	//�����ף��Զ�����
	Setboom(mine, ROW, COL, num_boom);
	//DisplayBoard(mine, ROW, COL);
	system("cls");
	DisplayBoard(show, ROW, COL);
	while(1)
	{
		////�Ų��ף�
		int c = Checkboom(mine, show, ROW, COL);
		if (c == 1)
		{
			printf("BOOM! GAME OVER!\n");
			printf("5Second later you will choose to play again or not\n");
			Sleep(5000);
			system("cls");
			break;
		}
		else if (c == 2)
		{
			printf("Congratulations! You win the game!\n");
			printf("5Second later you will choose to play again or not\n");
			Sleep(5000);
			system("cls");
			break;
		}
		else
		{
			////��ӡshow
			system("cls");
			DisplayBoard(show, ROW, COL);
		}

	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("Please input(1/0):>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("game\n");
			game();
			break;
		case 0:
			printf("exit the game\n");
			break;
		default:
			printf("unknown input,please retry");
			break;
		}

	} while (input);
	return 0;
}