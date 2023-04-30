#include<iostream>
#include "Lab4_loadfile.h"
#include "Lab4_data.h"
using namespace std;

extern CONF Lab4_read;
extern int** num_Lab4;
extern DATAITEM* Parr;

/***********************************************************************
�������ƣ�printf_Arr
��������: ��ӡ��ά����
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void printf_Arr()
{
	printf("����Ϊ�����ļ�:\n");
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
�������ƣ�printf_Struct
��������: ��ӡ�ṹ��
���������DataITME*&tribble
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void printf_Struct(DATAITEM* &tribble)
{
	printf("����Ϊ�������ļ�:\n");
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << tribble[i].item1 << ',';
		cout << tribble[i].item2 << ',';
		cout << tribble[i].item1 << endl;
	}
	return;
}

/***********************************************************************
�������ƣ�printf_Parr
��������: ��ӡָ������
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void printf_Parr()
{
	printf("����Ϊ�������ļ�\n");
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << Parr[i].item1 << ',';
		cout << Parr[i].item2 << ',';
		cout << Parr[i].item1 << endl;
	}
	return;
}

/***********************************************************************
�������ƣ�printf_DataNode
��������: ��ӡ����
���������DataNode*head
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void printf_DataNode(DataNode*& head)
{
	printf("����Ϊ�������ļ�\n");
	DataNode* p = head;
	printf("%d\n", head->nums_data1);//��ӡ������Ϣ
	p = p->pNext;    //����ӡͷ�ڵ���������е�ֵ 
	while (p != NULL)
	{
		printf("%d %d %d\n", p->nums_data1, p->nums_data2, p->nums_data3);
		p = p->pNext;
	}
	return;
}