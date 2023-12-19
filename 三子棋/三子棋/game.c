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
	printf("请输入落子坐标:>");
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	if (x - 1 >= 0 && x <= row && y - 1 >= 0 && y <= col)
	{
		if (board[x - 1][y - 1] == ' ')
			board[x - 1][y - 1] = '*';
		else
		{
			printf("该坐标已被占用，请重新选择\n");
			goto again;
		}
	}
	else
	{
		printf("输入非法坐标，请重新输入\n");
		goto again;
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
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
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == '*')//判断玩家横向是否构成
			{
				printf("你赢了！\n");
				return 1;
			}
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == '#')//判断电脑横向是否构成
			{
				printf("你输了！\n");
				return 1;
			}
		}
	}
	for (int i = 0;i < row - 2;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == '*')//判断玩家纵向是否构成
			{
				printf("你赢了！\n");
				return 1;
			}
			if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == '#')//判断电脑纵向是否构成
			{
				printf("你输了！\n");
				return 1;
			}
		}
	}
	for (int i = 0;i < row - 2;i++)//判断左上到右下的斜向是否构成
	{
		for (int j = 0;j < col-2;j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == '*')//玩家
			{
				printf("你赢了！\n");
				return 1;
			}
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == '#')//电脑
			{
				printf("你输了！\n");
				return 1;
			}
		}
	}
	for (int i = 0;i < row - 2;i++)//判断右上到左下的斜向是否构成
	{
		for (int j = 2;j < col;j++)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == '*')//玩家
			{
				printf("你赢了！\n");
				return 1;
			}
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == '#')//电脑
			{
				printf("你输了！\n");
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
	if (count == ROW * COL)//判断是否平局
	{
		printf("平局\n");
		return 1;
	}
	else
		return 0;
}