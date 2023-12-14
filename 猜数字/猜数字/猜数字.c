#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game()
{
	int guess = 0;
	int a = rand() % 100 + 1;
	while (1)
	{
		printf("请输入数字:");
		scanf("%d", &guess);
		if (guess == a)
		{
			printf("你猜对了\n");
			break;
		}
		else if (guess < a)
			printf("你猜小了\n");
		else
			printf("你猜大了\n");
	}
}
int main()
{
	int imput = 0;
	do
	{
		printf("*********************************************\n");
		printf("**************   1.start   ******************\n");
		printf("**************   0.exit    ******************\n");
		printf("*********************************************\n");
		printf("请选择:");
		scanf("%d", &imput);
		switch (imput)
		{
		case 1:
		{
			srand((unsigned int)time(NULL));
			game();
			break;
		}
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (imput);
	return 0;
}