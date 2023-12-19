#include "game.h"
void print()
{
	printf("****************************\n");
	printf("********1.  start  *********\n");
	printf("********0.  exit   *********\n");
	printf("****************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	displayboard(board, ROW, COL);
	while (1)
	{
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		if (is_win(board, ROW, COL))
			break;
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		if (is_win(board, ROW, COL))
			break;
	}
}
void initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
		for (int j = 0;j < col;j++)
			board[i][j] = ' ';
}
void displayboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0;i < row; i++)
	{
		for (int j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col-1)
				printf("|");
		}
		printf("\n");
		for (int j = 0;j < col;j++)
		{
			if (i == row - 1)
				break;
			printf("---");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	again:
	printf("��������������:>");
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	if (x - 1 >= 0 && x <= row && y - 1 >= 0 && y <= col)
	{
		if (board[x - 1][y - 1] == ' ')
			board[x - 1][y - 1] = '*';
		else
		{
			printf("�������ѱ�ռ�ã�������ѡ��\n");
			goto again;
		}
	}
	else
	{
		printf("����Ƿ����꣬����������\n");
		goto again;
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	while (1)
	{
		int a = rand() % row;
		int b = rand() % col;
		if (board[a][b] == ' ')
		{
			board[a][b] = '#';
			break;
		}
	}
}
int is_win(char board[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col-2;j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == '*')//�ж���Һ����Ƿ񹹳�
			{
				printf("��Ӯ�ˣ�\n");
				return 1;
			}
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == '#')//�жϵ��Ժ����Ƿ񹹳�
			{
				printf("�����ˣ�\n");
				return 1;
			}
		}
	}
	for (int i = 0;i < row - 2;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == '*')//�ж���������Ƿ񹹳�
			{
				printf("��Ӯ�ˣ�\n");
				return 1;
			}
			if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == '#')//�жϵ��������Ƿ񹹳�
			{
				printf("�����ˣ�\n");
				return 1;
			}
		}
	}
	for (int i = 0;i < row - 2;i++)//�ж����ϵ����µ�б���Ƿ񹹳�
	{
		for (int j = 0;j < col-2;j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == '*')//���
			{
				printf("��Ӯ�ˣ�\n");
				return 1;
			}
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == '#')//����
			{
				printf("�����ˣ�\n");
				return 1;
			}
		}
	}
	for (int i = 0;i < row - 2;i++)//�ж����ϵ����µ�б���Ƿ񹹳�
	{
		for (int j = 2;j < col;j++)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == '*')//���
			{
				printf("��Ӯ�ˣ�\n");
				return 1;
			}
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == '#')//����
			{
				printf("�����ˣ�\n");
				return 1;
			}
		}
	}
	int count = 0;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
			if (board[i][j] != ' ')
				count++;
	}
	if (count == ROW * COL)//�ж��Ƿ�ƽ��
	{
		printf("ƽ��\n");
		return 1;
	}
	else
		return 0;
}