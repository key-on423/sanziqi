#pragma once
#include<stdio.h>
#include<time.h>//ʱ���ͷ�ļ�ʹ��
#include<stdlib.h>//�����ͷ�ļ�ʹ��
#define Hang 3
#define Lie 3
//����
void InitBoard(char board[Hang][Lie], int hang, int lie);
void DisplayBoard(char board[Hang][Lie], int hang, int lie);
void Playermove(char board[Hang][Lie], int hang, int lie);
void Computermove(char board[Hang][Lie], int hang, int lie);
char Iswin(char board[Hang][Lie], int hang, int lie);

