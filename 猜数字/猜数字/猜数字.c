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
		printf("����������:");
		scanf("%d", &guess);
		if (guess == a)
		{
			printf("��¶���\n");
			break;
		}
		else if (guess < a)
			printf("���С��\n");
		else
			printf("��´���\n");
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
		printf("��ѡ��:");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (imput);
	return 0;
}