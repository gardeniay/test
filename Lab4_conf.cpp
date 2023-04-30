#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <ctime>
#include<fstream>
#include "Lab4_reset.h"
using namespace std;

/***********************************************************************
�������ƣ�CharToStr
�������ܣ��ַ�����תΪ�ַ���
���������cgar* contentChar
�� �� ֵ���ַ���
ģ����ʷ��

*************************************************************************/
string CharToStr(char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}


/***********************************************************************
�������ƣ�ModifyLineData
�������ܣ��޸�ĳһ�ļ���ĳһ������
���������const char* fileName, int lineNum, char* lineData
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void ModifyLineData(const char* fileName, int lineNum, char* lineData)
{
	ifstream in;
	in.open(fileName);

	string strFileData = "";
	int line = 1;
	char tmpLineData[1024] = { 0 };
	while (in.getline(tmpLineData, sizeof(tmpLineData)))
	{
		if (line == lineNum)
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(tmpLineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();

	//д���ļ�
	ofstream out;
	out.open(fileName);
	out.flush();
	out << strFileData;
	out.close();
}

/***********************************************************************
�������ƣ�change_initaal
�������ܣ��޸ĳ�ʼ�����ļ�
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void change_initial()
{
	while (1)
	{
		int line = 0, change, judge2 = 1; string s1;
		char tmp[100] = { 0 };
		printf("1.�޸�ʵ��3�����ļ�conf.ini�еĲ���\n");
		printf("0.������һ��\n");
		printf("������ѡ��:\n");
		scanf("%d", &change);
		fflush(stdin);
		if (change == 1)
		{
			while (judge2)
			{
				int choice;
				printf("1.�޸��ļ��洢Ŀ¼\n");
				printf("2.�޸��ļ�����\n");
				printf("3.�޸ĵ�һ������Ԫ�����ֵ\n");
				printf("4.�޸ĵ�һ������Ԫ����Сֵ\n");
				printf("5.�޸ĵ�����Ԫ�����ֵ\n");
				printf("6.�޸ĵ�����Ԫ����Сֵ\n");
				printf("7.�޸ļ�¼�������ֵ\n");
				printf("8.�޸ļ�¼������Сֵ\n");
				printf("0.������һ���˵�\n");
				scanf("%d", &choice);
				switch (choice)
				{
					judge2 = 1;
					//�޸�ʵ��3�����ļ�conf.ini�еĲ���
				case 1:
					printf("�������µ��ļ��洢Ŀ¼��\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸��ļ�����
				case 2:
					printf("�������µ��ļ����ƣ�\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸ĵ�һ������Ԫ�����ֵ
				case 3:
					printf("�������һ������Ԫ�����ֵ:\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸ĵ�һ������Ԫ����Сֵ
				case 4:
					printf("�������һ������Ԫ����Сֵ:\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸ĵ�����Ԫ�����ֵ
				case 5:
					printf("�����������Ԫ�����ֵ��\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸ĵ�����Ԫ����Сֵ
				case 6:
					printf("�����������Ԫ����Сֵ��\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸ļ�¼�������ֵ
				case 7:
					printf("�������¼�������ֵ��\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//�޸ļ�¼������Сֵ
				case 8:
					printf("�������¼������Сֵ\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//������һ���˵�
				case 0:
					judge2 = 0;
					break;
				}
			}
		}
		else if (change == 0)  break;
		else printf("��ѡ��Ĺ��ܲ���ȷ������������\n");
	}
	return;
}


