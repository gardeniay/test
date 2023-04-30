#include<iostream>
#include "Lab4_loadfile.h"
#include "Lab4_data.h"
using namespace std;

extern CONF Lab4_read;
extern int** num_Lab4;
extern DATAITEM* Parr;

/***********************************************************************
函数名称：printf_Arr
函数功能: 打印二维数组
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void printf_Arr()
{
	printf("以下为生成文件:\n");
	for (int i = 0; i < Lab4_read.number; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << num_Lab4[i][j] << ',';
		}
		cout << num_Lab4[i][2] << endl;
	}
	return;
}

/***********************************************************************
函数名称：printf_Struct
函数功能: 打印结构体
输入参数：DataITME*&tribble
返 回 值：无
模块历史：

*************************************************************************/
void printf_Struct(DATAITEM* &tribble)
{
	printf("以下为已生成文件:\n");
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << tribble[i].item1 << ',';
		cout << tribble[i].item2 << ',';
		cout << tribble[i].item1 << endl;
	}
	return;
}

/***********************************************************************
函数名称：printf_Parr
函数功能: 打印指针数组
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void printf_Parr()
{
	printf("以下为已生成文件\n");
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << Parr[i].item1 << ',';
		cout << Parr[i].item2 << ',';
		cout << Parr[i].item1 << endl;
	}
	return;
}

/***********************************************************************
函数名称：printf_DataNode
函数功能: 打印链表
输入参数：DataNode*head
返 回 值：无
模块历史：

*************************************************************************/
void printf_DataNode(DataNode*& head)
{
	printf("以下为已生成文件\n");
	DataNode* p = head;
	printf("%d\n", head->nums_data1);//打印条数信息
	p = p->pNext;    //不打印头节点的数据域中的值 
	while (p != NULL)
	{
		printf("%d %d %d\n", p->nums_data1, p->nums_data2, p->nums_data3);
		p = p->pNext;
	}
	return;
}