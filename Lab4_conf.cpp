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
函数名称：CharToStr
函数功能：字符出租转为字符串
输入参数：cgar* contentChar
返 回 值：字符串
模块历史：

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
函数名称：ModifyLineData
函数功能：修改某一文件中某一行数据
输入参数：const char* fileName, int lineNum, char* lineData
返 回 值：无
模块历史：

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

	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out << strFileData;
	out.close();
}

/***********************************************************************
函数名称：change_initaal
函数功能：修改初始配置文件
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void change_initial()
{
	while (1)
	{
		int line = 0, change, judge2 = 1; string s1;
		char tmp[100] = { 0 };
		printf("1.修改实验3配置文件conf.ini中的参数\n");
		printf("0.返回上一级\n");
		printf("请输入选项:\n");
		scanf("%d", &change);
		fflush(stdin);
		if (change == 1)
		{
			while (judge2)
			{
				int choice;
				printf("1.修改文件存储目录\n");
				printf("2.修改文件名称\n");
				printf("3.修改第一、二个元素最大值\n");
				printf("4.修改第一、二个元素最小值\n");
				printf("5.修改第三个元素最大值\n");
				printf("6.修改第三个元素最小值\n");
				printf("7.修改记录条数最大值\n");
				printf("8.修改记录条数最小值\n");
				printf("0.返回上一级菜单\n");
				scanf("%d", &choice);
				switch (choice)
				{
					judge2 = 1;
					//修改实验3配置文件conf.ini中的参数
				case 1:
					printf("请输入新的文件存储目录：\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改文件名称
				case 2:
					printf("请输入新的文件名称：\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改第一、二个元素最大值
				case 3:
					printf("请输入第一、二个元素最大值:\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改第一、二个元素最小值
				case 4:
					printf("请输入第一、二个元素最小值:\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改第三个元素最大值
				case 5:
					printf("请输入第三个元素最大值：\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改第三个元素最小值
				case 6:
					printf("请输入第三个元素最小值：\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改记录条数最大值
				case 7:
					printf("请输入记录条数最大值：\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//修改记录条数最小值
				case 8:
					printf("请输入记录条数最小值\n");
					cin >> s1;
					for (int i = 0; s1[i] != '\0'; i++)
					{
						tmp[i] = s1[i];
					}
					tmp[s1.length()] = '\0';
					ModifyLineData("D:\\conf.ini", line, tmp);
					break;
					//返回上一级菜单
				case 0:
					judge2 = 0;
					break;
				}
			}
		}
		else if (change == 0)  break;
		else printf("您选择的功能不正确，请重新输入\n");
	}
	return;
}


