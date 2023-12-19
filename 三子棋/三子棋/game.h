#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void print();//打印游戏开始页面
void game();//整个游戏开始到结束的执行
void initboard(char board[ROW][COL],int row, int col);//初始化棋盘
void displayboard(char board[ROW][COL], int row, int col);//显示棋盘
void playermove(char board[ROW][COL], int row, int col);//玩家下棋
void computermove(char board[ROW][COL], int row, int col);//电脑下棋

//判断游戏是否继续
//返回值：   1			0
//       游戏结束     游戏继续
int is_win(char board[ROW][COL], int row, int col);

