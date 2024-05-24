#include "game.h"
void InitBoard(char board[Hang][Lie], int hang, int lie)
{
	int j = 0;
	int k = 0;
	for (j = 0;j < hang;j++)
	{
		for (k = 0;k < lie;k++)
		{  //一行三个数初始为空格
			board[j][k] = ' ';
		}
	}
}
void DisplayBoard(char board[Hang][Lie], int hang, int lie)
{
	int j = 0;
	for (j = 0;j < hang;j++)//分为一组一组来打
	{
		int i = 0;
		for (i = 0;i < lie;i++)
		{  // 1.打印一行的数据 0 1 2
			printf(" %c ", board[j][i]);
			if (i < lie - 1)
			{
				printf("|");
			}
		}printf("\n");
		//2.打印分割行
		if (j < hang - 1)
		{
			for (i = 0;i < lie;i++)
			{
				printf("---");
				if (i < lie - 1)
					printf("|");
			}printf("\n");
		}
	}
}
void Playermove(char board[Hang][Lie], int hang, int lie)
{
	int x = 0;
	int y = 0;
	printf("玩家1走\n");
	while (1)
	{
		printf("请输入坐标\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= hang && y >= 1 && y <= lie)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("该位置已被占用\n");
			}
		}
		else
		{
			printf("非法输入\n");
		}
	}

}
void Computermove(char board[Hang][Lie], int hang, int lie)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	while (1)
	{
		x = rand() % hang;//模上一个数只能为<他的数 %3 为 0 1 2
		y = rand() % lie;//rand生成随机数
		if (board[x][y] == ' ')
		{
			board[x][y] = 'x';
			break;
		}

	}
	/*printf("玩家2走\n");
	while (1)
	{
		printf("请输入坐标\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= hang && y >= 1 && y <= lie)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("该位置已被占用\n");
			}
		}
		else
		{
			printf("非法输入\n");
		}
	}*/
}
int Isfull(char board[Hang][Lie], int hang, int lie)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < hang;i++)
	{
		for (j = 0;j < lie;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[Hang][Lie], int hang, int lie)
{
	int x = 0;
	for (x = 0;x < hang;x++)
	{   //横三行判断
		if (board[x][0] == board[x][1] && board[x][2] == board[x][1] && board[x][1] != ' ')
		{
			return board[x][0];
		}
	}
	for (x = 0;x < lie;x++)
	{ //竖三行判断
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x] && board[0][x] != ' ')
		{
			return board[0][x];
		}
	}
	//两斜边判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[0][0];

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[0][2];
	//判断格子是否满了（平局）
	if (1 == Isfull(board, Hang, Lie))
	{
		return 'Q';
	}
	//上述条件均不满足继续下棋
	return 'C';
}