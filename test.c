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
	char Mine[ROWS][COLS] = { 0 };//��Ų��úõ���
	char Show[ROWS][COLS] = { 0 };//����Ų����
	Init(Mine, ROWS, COLS,set1);//��ʼ��
	Init(Show, ROWS, COLS, set2);//��ʼ��
	Display(Show, ROW, COL);
	Putmine(Mine, ROW, COL);//����
	//Display(Mine, ROW, COL);//��ʾ
	//Showmine(Mine, ROW, COL);//���
	Clearmine(Mine,Show, ROW, COL);//����

	

}
void test()//���ѡ���ĸ�
{
	int input = 0;
	while (1)
	{
		menu();
		printf("������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����");
			break;
		default:
			printf("������������������:>\n");
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