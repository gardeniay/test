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
函数名称：changeinto_int
函数功能: 将字符数组转化为int型
输入参数：char a[]
返 回 值：int
模块历史：

*************************************************************************/
//将字符数组转化为int型
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
函数名称：changeinto_int_s
函数功能: 将字符串变量转化为int型
输入参数：string a
返 回 值：int
模块历史：

*************************************************************************/
//将字符串变量转化为int型
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
函数名称：creat_Array
函数功能: 生成二维数组
输入参数：int n
返 回 值：无
模块历史：

*************************************************************************/
//创建一个二维数组
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
函数名称：My_find_path
函数功能: 提取字符串中地址
输入参数：string a
返 回 值：无
模块历史：

*************************************************************************/
//将a中储存的地址存入结构体
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
函数名称：My_check
函数功能: 检测输入地址是否合法
输入参数：string a
返 回 值：bool
模块历史：

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
函数名称：isNum
函数功能: 检测输入是否为数字
输入参数：char str[]
返 回 值：bool
模块历史：

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


