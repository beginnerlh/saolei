#define _CRT_SECURE_NO_WARNINGS 
#ifndef _GAME_H_
#define GAME_H
#define ROW  9 
#define COL  9
#define ROWS  (ROW+2) 
#define COLS  (COL+2)
#define easycount 10
 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>



void Init(char Mine[ROWS][COLS], int rows, int cols, char set1);

void Display(char Mine[ROWS][COLS],int row,int  col);

void Putmine(char Mine[ROWS][ROWS], int row,int  col);

void Showmine(char Mine[ROWS][ROWS], int row, int  col);

void Clearmine(char Mine[ROWS][COLS],char Show[ROWS][COLS],int row, int col);









#endif