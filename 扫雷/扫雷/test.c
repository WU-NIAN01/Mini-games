#include "game.h"
void Init_Game()
{
	printf("**************************\n");
	printf("*******   1.play   *******\n");
	printf("*******   0.exit   *******\n");
	printf("**************************\n");
}
void game()
{
	char conceal[ROW1][COL1] = { 0 };//存放雷的棋盘
	char show[ROW1][COL1] = { 0 };//玩家所看到的棋盘
	Init_Board(conceal, ROW1, COL1, '0');
	Init_Board(show, ROW1, COL1, '*');
	Mine(conceal, ROW, COL, NUMBER);
	Display(show, ROW, COL);
	Player_Move(show, conceal, ROW, COL);
}
int main()
{
	int input = 0;
	do
	{
		Init_Game();
		printf("请输入数字:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
			break;
		default:
			printf("输入非法数字，请重新输入\n");
		}
	} while (input);
	return 0;
}
