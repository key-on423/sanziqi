#include "game.h"
void InitBoard(char board[Hang][Lie], int hang, int lie)
{
	int j = 0;
	int k = 0;
	for (j = 0;j < hang;j++)
	{
		for (k = 0;k < lie;k++)
		{  //һ����������ʼΪ�ո�
			board[j][k] = ' ';
		}
	}
}
void DisplayBoard(char board[Hang][Lie], int hang, int lie)
{
	int j = 0;
	for (j = 0;j < hang;j++)//��Ϊһ��һ������
	{
		int i = 0;
		for (i = 0;i < lie;i++)
		{  // 1.��ӡһ�е����� 0 1 2
			printf(" %c ", board[j][i]);
			if (i < lie - 1)
			{
				printf("|");
			}
		}printf("\n");
		//2.��ӡ�ָ���
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
	printf("���1��\n");
	while (1)
	{
		printf("����������\n");
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
				printf("��λ���ѱ�ռ��\n");
			}
		}
		else
		{
			printf("�Ƿ�����\n");
		}
	}

}
void Computermove(char board[Hang][Lie], int hang, int lie)
{
	int x = 0;
	int y = 0;
	printf("������\n");
	while (1)
	{
		x = rand() % hang;//ģ��һ����ֻ��Ϊ<������ %3 Ϊ 0 1 2
		y = rand() % lie;//rand���������
		if (board[x][y] == ' ')
		{
			board[x][y] = 'x';
			break;
		}

	}
	/*printf("���2��\n");
	while (1)
	{
		printf("����������\n");
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
				printf("��λ���ѱ�ռ��\n");
			}
		}
		else
		{
			printf("�Ƿ�����\n");
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
	{   //�������ж�
		if (board[x][0] == board[x][1] && board[x][2] == board[x][1] && board[x][1] != ' ')
		{
			return board[x][0];
		}
	}
	for (x = 0;x < lie;x++)
	{ //�������ж�
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x] && board[0][x] != ' ')
		{
			return board[0][x];
		}
	}
	//��б���ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[0][0];

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[0][2];
	//�жϸ����Ƿ����ˣ�ƽ�֣�
	if (1 == Isfull(board, Hang, Lie))
	{
		return 'Q';
	}
	//�����������������������
	return 'C';
}