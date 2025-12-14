#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//初始化棋盘
void Initborad(char board[ROW][COL],int row,int col);

//打印棋盘
void Displayboard(char board[ROW][COL],int row,int col);

//下棋
//玩家
void PlayerMove(char board[ROW][COL], int row,int col);
//电脑
//找空白的位置随机下
void ComputerMove(char board[ROW][COL], int row, int col);

//玩家赢 ‘*’
//电脑赢 #
//平局 Q
//继续 c
char Iswin(char board[ROW][COL], int row, int col);