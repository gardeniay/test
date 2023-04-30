#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stdlib.h>

/***********************************************************************
函数名称：run_Lab3
函数功能: 运行实验3
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void run_Lab3()
{
	system("C:\\Users\\86188\\source\\repos\\实验3\\x64\\Debug\\实验3.exe");
	printf("已运行实验3生成文件在指定位置!\n");
	return;
}

/***********************************************************************
函数名称：recall
函数功能：运行实验3
输入参数：int mode,char* filepath,int num
返 回 值：无
模块历史：

*************************************************************************/
void re_call(int mode, char* filepath, int number)
{
	char function[100] = "C:\\Users\\86188\\source\\repos\\实验3\\x64\\Debug\\实验3.exe";
	if (mode == 1)
	{
		system(function);
	}
	else if (mode == 2)
	{
		int len = 0, m = number;
		while (m != 0)
		{
			m = m / 10;
			len++;
		}
		char str[10];
		_itoa_s(number, str, 10);
		str[len] = '\0';
		strcat(function, " ");
		strcat(function, filepath);
		strcat(function, " ");
		strcat(function, str);
		system(function);
	}
}