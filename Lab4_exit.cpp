#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/***********************************************************************
函数名称：Exit
函数功能：退出程序
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void Exit()
{
	extern int is_run;
	is_run = 0;
	printf("感谢您的使用!\n");
	return;
}