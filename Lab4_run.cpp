#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Lab4_main.h"
#include"Lab4_data.h"
#include"Lab4_call.h"
#include <string>
#include <cstdio>
#include <cstring>
#include <ctime>
#include<fstream>
#include "Lab4_conf.h"
#include "Lab4_reset.h"
#include "Lab4_exit.h"
#include "Lab4_loadfile.h"
#include "Lab4_reset.h"
using namespace std;

int run_mod, is_run = 1;
CONF Lab4_read;

/***********************************************************************
�������ƣ�run_Lab4
��������: ʵ��4������
���������int argc,char* argv[]
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void run_Lab4(int argc, char* argv[])
{

	while (is_run)
	{
		int cnt = 0;
		string read_s[100];
		ifstream inf;
		inf.open("D:\\conf (2).ini");
		if (!inf.is_open())
		{
			cout << "��ȡ�ļ�ʧ��" << endl;
			return;
		}
		while (getline(inf, read_s[cnt]))
		{
			cnt++;
		}
		for (int i = 0; i < read_s[0].length(); i++)
		{
			Lab4_read.filename[i] = read_s[0][i];
		}
		for (int i = 0; i < read_s[1].length(); i++)
		{
			Lab4_read.filesavepath[i] = read_s[1][i];
		}
		Lab4_read.number = changeinto_int_s(read_s[2]);
		Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
		Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
		Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
		Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
		Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
		Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

		printf("�ſ����ʵ��4����:\n");
		printf("1. ����ʵ��3�������ɼ�¼�ļ�\n");
		printf("2.��ȡָ�����ݼ�¼�ļ�(��ά����洢��ʽ)\n");
		printf("3.��ȡָ�����ݼ�¼�ļ����ṹ������洢��ʽ)\n");
		printf("4.��ȡָ�����ݼ�¼�ļ���ָ������洢��ʽ��\n");
		printf("5.��ȡָ�����ݼ�¼�ļ�������洢��ʽ��\n");
		printf("6. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�����ά���鷽ʽ�洢��\n");
		printf("7. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ṹ�����鷽ʽ�洢��\n");
		printf("8. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ���ָ�����鷽ʽ�洢��\n");
		printf("9. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�������ʽ�洢��\n");
		printf("10. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶�ά���鷽ʽ�洢��\n");
		printf("11. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨽ṹ�����鷽ʽ�洢��\n");
		printf("12. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�������ָ�����鷽ʽ�洢��\n");
		printf("13. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�����������ʽ�洢��\n");
		printf("14. ��������ʵ��3�����ļ�����ֵ\n");
		printf("15. ��������ʵ��4����ģʽ\n0.�˳�\n");
		printf("��������Ҫִ�еĳ������:\n");

		while (scanf("%d", &run_mod) != 1 || (run_mod < 0 || run_mod > 15))
		{
			printf("��������ȷ�����!\n");
			fflush(stdin);
		}
		switch (run_mod)
		{
		case 0: Exit(); break;
		case 1: run_Lab3(); break;
		case 2:use_Arr(); break;
		case 3:use_Struct(); break;
		case 4:use_pointArr(); break;
		case 5:use_LinkNode(); break;
		case 6:use_Arr_Lab3(); break;
		case 7:use_Struct_Lab3();break;
		case 8:use_pointArr_Lab3();break;
		case 9:use_LinkNode_Lab3();break;
		case 10:use_Arr_Lab3_sort(); break;
		case 11:use_Struct_Lab3_sort(); break;
		case 12:use_pointArr_Lab3_sort(); break;
		case 13:use_LinkNode_Lab3_sort(); break;
		case 14:change_initial(); break;
		case 15:reset_mod(); break;
		default:break;
		}
	}
}