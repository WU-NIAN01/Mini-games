#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void print();//��ӡ��Ϸ��ʼҳ��
void game();//������Ϸ��ʼ��������ִ��
void initboard(char board[ROW][COL],int row, int col);//��ʼ������
void displayboard(char board[ROW][COL], int row, int col);//��ʾ����
void playermove(char board[ROW][COL], int row, int col);//�������
void computermove(char board[ROW][COL], int row, int col);//��������

//�ж���Ϸ�Ƿ����
//����ֵ��   1			0
//       ��Ϸ����     ��Ϸ����
int is_win(char board[ROW][COL], int row, int col);

