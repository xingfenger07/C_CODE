#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("**1. play                 0. exit**\n");
	printf("***********************************\n");

}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘的函数
	Initborad(board, ROW, COL);
	Displayboard(board,ROW,COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		Displayboard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		Displayboard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
		printf("平局\n");
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数生成起点
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
}