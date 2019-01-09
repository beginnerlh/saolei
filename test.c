#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void menu()
{
	printf("*************************************\n");
	printf("************1.play    0.exit*********\n");
	printf("*************************************\n");
}
void game()
{
	char set1 = '0';
	char set2 = '*';
	char Mine[ROWS][COLS] = { 0 };//存放布置好的雷
	char Show[ROWS][COLS] = { 0 };//存放排查的雷
	Init(Mine, ROWS, COLS,set1);//初始化
	Init(Show, ROWS, COLS, set2);//初始化
	Display(Show, ROW, COL);
	Putmine(Mine, ROW, COL);//埋雷
	//Display(Mine, ROW, COL);//显示
	//Showmine(Mine, ROW, COL);//检查
	Clearmine(Mine,Show, ROW, COL);//排雷

	

}
void test()//检测选择哪个
{
	int input = 0;
	while (1)
	{
		menu();
		printf("请输入选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束");
			break;
		default:
			printf("输入有误！请重新输入:>\n");
		}
	}

}
int main()
{
	srand((unsigned int)time(0));
	test();
	system("pause");
	return 0;
}