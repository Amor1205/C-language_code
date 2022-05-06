#pragma once
#include<stdio.h>
#include<time.h>
#include<windows.h>
#define ROW 9
#define COL 9
#define num_boom 10
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char arr[ROWS][COLS], int x, int y,char set);
void DisplayBoard(char arr[ROWS][COLS], int x, int y);
void Setboom(char arr[ROWS][COLS], int x, int y,int num);
int Checkboom(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x,int y);
char NUM(char arr[ROWS][COLS], int a, int b);
