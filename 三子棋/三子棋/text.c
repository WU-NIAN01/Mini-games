#include "game.h"
int main()
{
	int imput = 0;
	srand((unsigned)time(NULL));
	do
	{
		print();
		printf("请输入数字:>");
		scanf("%d", &imput);
		switch (imput)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
			break;
		default:
		{
			printf("输入错误，请重新输入\n");
			break;
		}
		}
	} while (imput);
	return 0;
}