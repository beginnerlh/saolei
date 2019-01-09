#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void Init(char Mine[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j <cols; j++)
		{
			Mine[i][j] = set;
		}
	}
}
void Display(char Mine[ROWS][COLS], int row, int  col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (k = 0; k <= col; k++)
	{
		printf("%d  ", k);
	}
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf("%d  ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c  ", Mine[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

}
void Putmine(char Mine[ROWS][ROWS], int row, int  col)
{
	int count = easycount;
	int x = 0;
	int y = 0;
	while (count>0)
	{
		x = rand() % ROW+ 1;
		y = rand() % COL + 1;
		if (Mine[x][y]!='0'+1)
		{
			Mine[x][y] = 1+'0';
			count--;
		}
	}
}
//void Showmine(char aee[ROWS][ROWS], int row, int  col)
//{
//	int i = 0;
//	int k = 0;
//	for (k = 0; k <= col; k++)
//	{
//		printf("%d  ", k);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d  ", i);
//		int j = 0;
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c  ", aee[i][j]);
//		}
//		printf("\n");
//	//	printf("  --------------------------\n");
//	}
//}
void ExpansionMine(char mine[ROWS][COLS], char show[ROWS][COLS], int i, int j){
	if (Getmine(mine, i, j) == 0){
		show[i][j] = ' ';
		//再次遍历周围的雷
		if ((i - 1) > 0 && show[i - 1][j] == '*'){
			//	printf("1\n");
			ExpansionMine(mine, show, i - 1, j);//递归
		}
		if (i - 1 > 0 && j + 1 <= COL && show[i - 1][j + 1] == '*'){
			ExpansionMine(mine, show, i - 1, j + 1);
		}
		if (j + 1 <= 9 && show[i][j + 1] == '*'){
			ExpansionMine(mine, show, i, j + 1);
		}
		if (i + 1 <= 9 && j + 1 <= 9 && show[i + 1][j + 1] == '*'){
			ExpansionMine(mine, show, i + 1, j + 1);
		}
		if (i + 1 <= 9 && show[i + 1][j] == '*'){
			ExpansionMine(mine, show, i + 1, j);
		}
		if (i + 1 <= 9 && j - 1 >0 && show[i + 1][j - 1] == '*'){
			ExpansionMine(mine, show, i + 1, j - 1);
		}
		if (j - 1 > 0 && show[i][j - 1] == '*'){
			ExpansionMine(mine, show, i, j - 1);
		}
		if (i - 1 > 0 && j - 1 > 0 && show[i - 1][j + 1] == '*'){
			ExpansionMine(mine, show, i - 1, j + 1);
		}
	}
	else{//周边有雷
		show[i][j] =Getmine(mine, i, j) + '0';
	}
}
int Getmine(char mine[ROWS][COLS], int x, int y){

	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}

void Clearmine(char Mine[ROWS][COLS],char Show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;

	while (win< ROW*COL - easycount)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
		{
			ExpansionMine(Mine, Show, x, y);
			if (Mine[x][y] == '1')
			{
				printf("菜鸡   你死了\n");
				Display(Mine, ROW, COL);
				break;
			}
			else
			{
				int count= Getmine(Mine, x, y);
				Show[x][y] = count + '0';
				Display(Show, ROW, COL);
			}
		}
		else
		{
			printf("坐标非法，请重新输入->\n");
		}
	}
	if (win == ROW*COL - easycount)
	{
		printf("恭喜你，排雷成功\n");
	}
}