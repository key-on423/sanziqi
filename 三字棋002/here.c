#include "game.h"
//#include <stdio.h><unistd.h>
void menu()
{
	/*printf("****************************\n");
	printf("****    1.play 2.exit   ****\n");
	printf("****************************\n");*/
	char arr1[] = { "***************************" };
	char arr2[] = { "---   本游戏由LQN制作   ---" };
	char arr4[] = { "***    1.play 2.exit    ***" };
	char arr3[] = { "***************************" };
	char arr5[] = { " ---- 井字棋测试1.0版本 ---- " };
	char arr6[] = { "*****************************" };
	int left = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int right = sz;
	while (left <= right)
	{
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];
		arr3[left] = arr4[left];
		arr3[right] = arr4[right];
		arr6[left] = arr5[left];
		arr6[right] = arr5[right];
		printf("%s\n", arr1);
		printf("%s\n", arr3);
		printf("%s\n", arr6);
		Sleep(24);
		system("cls");
		left++;
		right++;

	}
	printf("%s\n", arr1);
	printf("%s\n", arr3);
	printf("%s\n", arr6);
}
void game()
{
	char ret = 0;
	//数组 存放走出的棋盘信息
	char board[Hang][Lie] = { 0 };//全部空格
	//初始化棋盘
	InitBoard(board, Hang, Lie);
	//打印棋盘
	DisplayBoard(board, Hang, Lie);
	while (1)
	{
		Playermove(board, Hang, Lie);//下一次打印一次 判断一次
		DisplayBoard(board, Hang, Lie);
		Iswin(board, Hang, Lie);
		ret = Iswin(board, Hang, Lie);
		if (ret != 'C')
		{
			break;
		}
		Computermove(board, Hang, Lie);
		DisplayBoard(board, Hang, Lie);
		Iswin(board, Hang, Lie);
		ret = Iswin(board, Hang, Lie);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == 'O')
	{
		printf("玩家1获胜\n");
		Sleep(2000);
	}
	else if (ret == 'X')
	{
		printf("电脑获胜\n");
		/*printf("玩家2获胜\n");*/
		Sleep(2000);
	}
	else
	{
		printf("平局\n");
		Sleep(2000);
	}

}
void test()
{
	srand((unsigned int)time(NULL));//在测试函数中声明一次
	int input = 0;
	do {
		menu();
		printf("请选择：\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;

		}

	} while (input);


}
int main()
{
	test();
	return 0;
}