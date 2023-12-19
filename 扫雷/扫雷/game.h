#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9//设置棋盘行数
#define COL 9//设置棋盘列数
#define ROW1 ROW+2
#define COL1 COL+2
#define NUMBER 10
void Init_Game();//打印游戏初始界面
void game();//开始游戏到结束
void Init_Board(char board[ROW1][COL1], int row, int col, char a);//初始化棋盘
void Display(char board[ROW1][COL1], int row, int col);//显示棋盘
void Mine(char board[ROW1][COL1], int row, int col, int number);//布置雷
int Mine_Count(char conceal[ROW1][COL1], int x, int y);//排查周围雷的个数
void Player_Move(char show[ROW1][COL1], char conceal[ROW1][COL1], int row, int col);//玩家排雷


