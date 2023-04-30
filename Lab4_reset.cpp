#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Lab4_data.h"
using namespace std;


/***********************************************************************
函数名称：reset_mod
函数功能: 更改实验4运行模式
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void reset_mod()
{
	int flag_mod = 1;
	int is_reset=1;
	while (is_reset)
	{
		printf("请选择工作模式:\n1.自动模式\n2.交互模式\n");
		while (scanf("%d", &flag_mod) != 1 || (flag_mod <= 0 || flag_mod > 2))
		{
			printf("请输入正确的序号!\n");
			fflush(stdin);
		}
		if (flag_mod == 1)
		{
			printf("当前模式为自动模式\n");
		}
		else
		{
			printf("当前模式为交互模式\n");
		}
		printf("请问是否要继续更改模式:\n");
		printf("1.需要\n");
		printf("2.不需要\n");
		int is_change;
		cin >> is_change;
		if (is_change == 2)break;
	}
	return;
}