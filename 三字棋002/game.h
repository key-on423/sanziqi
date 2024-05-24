#pragma once
#include<stdio.h>
#include<time.h>//时间戳头文件使用
#include<stdlib.h>//随机数头文件使用
#define Hang 3
#define Lie 3
//声明
void InitBoard(char board[Hang][Lie], int hang, int lie);
void DisplayBoard(char board[Hang][Lie], int hang, int lie);
void Playermove(char board[Hang][Lie], int hang, int lie);
void Computermove(char board[Hang][Lie], int hang, int lie);
char Iswin(char board[Hang][Lie], int hang, int lie);

