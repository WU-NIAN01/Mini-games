#include "game.h"
void Init_Board(char board[ROW1][COL1], int row, int col,char a)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
			board[i][j] = a;
	}
}
void Display(char board[ROW1][COL1], int row, int col)
{
	for (int i = 2;i < col;i++)
		printf("-");
	printf("扫雷游戏");
	for (int i = 2;i < col;i++)
		printf("-");
	printf("\n ");
	for (int i = 0;i <= col;i++)
		printf("%d ", i);
	printf("\n");
	for (int i = 1;i <= row;i++)
	{
		printf(" %d ", i);
		for (int j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	for (int i = 2;i < col;i++)
		printf("-");
	printf("扫雷游戏");
	for (int i = 2;i < col;i++)
		printf("-");
	printf("\n");
}
void Mine(char board[ROW1][COL1], int row, int col, int number)
{
	int count = number;
	srand((unsigned int)time(NULL));
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int Mine_Count(char conceal[ROW1][COL1], int x, int y)
{
	return conceal[x - 1][y - 1] + conceal[x - 1][y] + conceal[x - 1][y + 1] +
		conceal[x][y - 1] + conceal[x][y + 1] + conceal[x + 1][y - 1] +
		conceal[x + 1][y] + conceal[x + 1][y + 1] - 8 * '0';
}
void Player_Move(char show[ROW1][COL1], char conceal[ROW1][COL1], int row, int col)
{
	int x = 0, y = 0;
	int count = 0;
	while (count < row*col-NUMBER)
	{
		printf("请输入需要排查的坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (conceal[x][y] == '1')
			{
				printf("boom！\n");
				Display(conceal, ROW, COL);
				break;
			}
			else
			{
				if (show[x][y] != '*')
					printf("该坐标已被排查，请重新输入\n");
				else
				{
					int tmp = Mine_Count(conceal, x, y);
					show[x][y] = tmp + '0';
					count++;
					if (show[x][y] == '0')
					{
						tmp = Mine_Count(conceal, x - 1, y - 1);
						show[x - 1][y - 1] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x - 1, y);
						show[x - 1][y] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x - 1, y + 1);
						show[x - 1][y + 1] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x, y + 1);
						show[x][y + 1] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x, y - 1);
						show[x][y - 1] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x + 1, y - 1);
						show[x + 1][y - 1] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x + 1, y);
						show[x + 1][y] = tmp + '0';
						count++;
						tmp = Mine_Count(conceal, x + 1, y + 1);
						show[x + 1][y + 1] = tmp + '0';
						count++;
					}
				}
			}
		}
		Display(show, row, col);
	}
	if (count == row * col - NUMBER)
	{
		printf("恭喜通关！\n");
		Dispaly(conceal, row, col);
	}
}