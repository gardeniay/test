#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Lab4_data.h"
using namespace std;


/***********************************************************************
�������ƣ�reset_mod
��������: ����ʵ��4����ģʽ
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void reset_mod()
{
	int flag_mod = 1;
	int is_reset=1;
	while (is_reset)
	{
		printf("��ѡ����ģʽ:\n1.�Զ�ģʽ\n2.����ģʽ\n");
		while (scanf("%d", &flag_mod) != 1 || (flag_mod <= 0 || flag_mod > 2))
		{
			printf("��������ȷ�����!\n");
			fflush(stdin);
		}
		if (flag_mod == 1)
		{
			printf("��ǰģʽΪ�Զ�ģʽ\n");
		}
		else
		{
			printf("��ǰģʽΪ����ģʽ\n");
		}
		printf("�����Ƿ�Ҫ��������ģʽ:\n");
		printf("1.��Ҫ\n");
		printf("2.����Ҫ\n");
		int is_change;
		cin >> is_change;
		if (is_change == 2)break;
	}
	return;
}