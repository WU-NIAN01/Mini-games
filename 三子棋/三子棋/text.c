#include "game.h"
int main()
{
	int imput = 0;
	srand((unsigned)time(NULL));
	do
	{
		print();
		printf("����������:>");
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
			printf("�����������������\n");
			break;
		}
		}
	} while (imput);
	return 0;
}