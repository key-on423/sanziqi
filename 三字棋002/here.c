#include "game.h"
//#include <stdio.h><unistd.h>
void menu()
{
	/*printf("****************************\n");
	printf("****    1.play 2.exit   ****\n");
	printf("****************************\n");*/
	char arr1[] = { "***************************" };
	char arr2[] = { "---   ����Ϸ��LQN����   ---" };
	char arr4[] = { "***    1.play 2.exit    ***" };
	char arr3[] = { "***************************" };
	char arr5[] = { " ---- ���������1.0�汾 ---- " };
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
	//���� ����߳���������Ϣ
	char board[Hang][Lie] = { 0 };//ȫ���ո�
	//��ʼ������
	InitBoard(board, Hang, Lie);
	//��ӡ����
	DisplayBoard(board, Hang, Lie);
	while (1)
	{
		Playermove(board, Hang, Lie);//��һ�δ�ӡһ�� �ж�һ��
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
		printf("���1��ʤ\n");
		Sleep(2000);
	}
	else if (ret == 'X')
	{
		printf("���Ի�ʤ\n");
		/*printf("���2��ʤ\n");*/
		Sleep(2000);
	}
	else
	{
		printf("ƽ��\n");
		Sleep(2000);
	}

}
void test()
{
	srand((unsigned int)time(NULL));//�ڲ��Ժ���������һ��
	int input = 0;
	do {
		menu();
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;

		}

	} while (input);


}
int main()
{
	test();
	return 0;
}