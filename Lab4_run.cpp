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
函数名称：run_Lab4
函数功能: 实验4主函数
输入参数：int argc,char* argv[]
返 回 值：无
模块历史：

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
			cout << "读取文件失败" << endl;
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

		printf("张俊峰的实验4程序:\n");
		printf("1. 调用实验3程序生成记录文件\n");
		printf("2.读取指定数据记录文件(二维数组存储方式)\n");
		printf("3.读取指定数据记录文件（结构体数组存储方式)\n");
		printf("4.读取指定数据记录文件（指针数组存储方式）\n");
		printf("5.读取指定数据记录文件（链表存储方式）\n");
		printf("6. 调用实验3生成数据记录文件，同时读取数据记录文件（二维数组方式存储）\n");
		printf("7. 调用实验3生成数据记录文件，同时读取数据记录文件（结构体数组方式存储）\n");
		printf("8. 调用实验3生成数据记录文件，同时读取数据记录文件（指针数组方式存储）\n");
		printf("9. 调用实验3生成数据记录文件，同时读取数据记录文件（链表方式存储）\n");
		printf("10. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（二维数组方式存储）\n");
		printf("11. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（结构体数组方式存储）\n");
		printf("12. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（指针数组方式存储）\n");
		printf("13. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（链表方式存储）\n");
		printf("14. 重新设置实验3配置文件参数值\n");
		printf("15. 重新设置实验4工作模式\n0.退出\n");
		printf("请输入您要执行的程序序号:\n");

		while (scanf("%d", &run_mod) != 1 || (run_mod < 0 || run_mod > 15))
		{
			printf("请输入正确的序号!\n");
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