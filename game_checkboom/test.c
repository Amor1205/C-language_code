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
	//选择游戏难度
	//choose_dif();
	char mine[ROWS][COLS] = { 0 };// = { '0' }错误，不完全初始化//存放布置雷的信息
	char show[ROWS][COLS] = { 0 };// = { '*' };//存放排查雷的信息
	//初始化数组内容为指定的内容
	InitBoard(mine, ROW, COL,'0');
	InitBoard(show, ROW, COL,'*');
	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);
	//设置雷，自动设置
	Setboom(mine, ROW, COL, num_boom);
	//DisplayBoard(mine, ROW, COL);
	system("cls");
	DisplayBoard(show, ROW, COL);
	while(1)
	{
		////排查雷，
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
			////打印show
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