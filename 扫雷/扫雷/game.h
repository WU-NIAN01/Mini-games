#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9//������������
#define COL 9//������������
#define ROW1 ROW+2
#define COL1 COL+2
#define NUMBER 10
void Init_Game();//��ӡ��Ϸ��ʼ����
void game();//��ʼ��Ϸ������
void Init_Board(char board[ROW1][COL1], int row, int col, char a);//��ʼ������
void Display(char board[ROW1][COL1], int row, int col);//��ʾ����
void Mine(char board[ROW1][COL1], int row, int col, int number);//������
int Mine_Count(char conceal[ROW1][COL1], int x, int y);//�Ų���Χ�׵ĸ���
void Player_Move(char show[ROW1][COL1], char conceal[ROW1][COL1], int row, int col);//�������


