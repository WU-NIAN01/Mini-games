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
	char conceal[ROW1][COL1] = { 0 };//����׵�����
	char show[ROW1][COL1] = { 0 };//���������������
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
		printf("����������:");
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
			printf("����Ƿ����֣�����������\n");
		}
	} while (input);
	return 0;
}
