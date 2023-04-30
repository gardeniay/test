#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Lab4_main.h"
#include"Lab4_data.h"
#include <string>
#include <cstdio>
#include <cstring>
#include <ctime>
#include<fstream>
using namespace std;

/***********************************************************************
�������ƣ�changeinto_int
��������: ���ַ�����ת��Ϊint��
���������char a[]
�� �� ֵ��int
ģ����ʷ��

*************************************************************************/
//���ַ�����ת��Ϊint��
int changeinto_int(char a[])
{
	int n1 = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		n1 = n1 * 10 + a[i] - '0';
	}
	return n1;
}

/***********************************************************************
�������ƣ�changeinto_int_s
��������: ���ַ�������ת��Ϊint��
���������string a
�� �� ֵ��int
ģ����ʷ��

*************************************************************************/
//���ַ�������ת��Ϊint��
int changeinto_int_s(string a)
{
	int n1 = 0;
	for (int i = 0; i < a.length(); i++)
	{
		n1 = n1 * 10 + a[i] - '0';
	}
	return n1;
}

/***********************************************************************
�������ƣ�creat_Array
��������: ���ɶ�ά����
���������int n
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
//����һ����ά����
void creat_Array(int n)
{
	extern int** num_Lab4;
	num_Lab4 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		num_Lab4[i] = new int[3];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			srand((unsigned)time(NULL) + (unsigned)rand());
			num_Lab4[i][j] = rand() % 100;
		}
	}
	return;
}

/***********************************************************************
�������ƣ�My_find_path
��������: ��ȡ�ַ����е�ַ
���������string a
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
//��a�д���ĵ�ַ����ṹ��
void My_find_path(string a)
{
	extern CONF Lab4_read;
	int flag = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '\\')
		{
			flag = 1;
		}
	}
	if (flag == 1 && a[a.length()] != '\\')
	{
		int position = 0, j = 0;
		for (int i = a.length() - 1; i >= 0; i--)
		{
			if (a[i] == '\\')
			{
				position = i;
				break;
			}
		}
		memset(Lab4_read.filename, 0, sizeof(Lab4_read.filename));
		memset(Lab4_read.filesavepath, 0, sizeof(Lab4_read.filesavepath));
		for (int i = 0; i < position + 1; i++)
		{
			Lab4_read.filename[i] = a[i];
		}
		for (int i = position + 1; i < a.length(); i++, j++)
		{
			Lab4_read.filesavepath[j] = a[i];
		}
	}
	else if (flag == 1 && a[a.length()] == '\\')
	{
		memset(Lab4_read.filesavepath, 0, sizeof(Lab4_read.filesavepath));
		for (int i = 0; i < a.length()-1; i++)
		{
			Lab4_read.filesavepath[i] = a[i];
		}
	}
	else if (flag == 0)
	{
		memset(Lab4_read.filename, 0, sizeof(Lab4_read.filename));
		for (int i = 0; i < a.length(); i++)
		{
			Lab4_read.filename[i] = a[i];
		}
	}
	return;
}

/***********************************************************************
�������ƣ�My_check
��������: ��������ַ�Ƿ�Ϸ�
���������string a
�� �� ֵ��bool
ģ����ʷ��

*************************************************************************/
bool My_check(string a)
{
	for (auto i = a.begin(); i != a.end(); i++)
	{
		if ((*i == '*') || (*i == '?'))
		{
			return false;
		}
		else if (*i == '/' || *i == '<' || *i == '>' || *i == '|')
		{
			return false;
		}
	}
	return true;
}

/***********************************************************************
�������ƣ�isNum
��������: ��������Ƿ�Ϊ����
���������char str[]
�� �� ֵ��bool
ģ����ʷ��

*************************************************************************/
bool isNum(char str[])
{
	if (strlen(str) > 1 && str[0] == 0)
	{
		return false;
	}
	if (strlen(str) == 1 && str[0] == '\n')
	{
		return true;
	}
	for (int i = 0; i < strlen(str); i++)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
		{
			return false;
		}
	}
	return true;
}


