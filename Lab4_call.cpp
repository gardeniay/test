#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stdlib.h>

/***********************************************************************
�������ƣ�run_Lab3
��������: ����ʵ��3
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void run_Lab3()
{
	system("C:\\Users\\86188\\source\\repos\\ʵ��3\\x64\\Debug\\ʵ��3.exe");
	printf("������ʵ��3�����ļ���ָ��λ��!\n");
	return;
}

/***********************************************************************
�������ƣ�recall
�������ܣ�����ʵ��3
���������int mode,char* filepath,int num
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void re_call(int mode, char* filepath, int number)
{
	char function[100] = "C:\\Users\\86188\\source\\repos\\ʵ��3\\x64\\Debug\\ʵ��3.exe";
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