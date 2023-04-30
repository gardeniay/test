#pragma warning(disable:4996);
#include<iostream>
#include"Lab4_main.h"
#include "Lab4_reset.h"
#include "Lab4_conf.h"
#include "Lab4_view.h"
#include "Lab4_call.h"
#include "Lab4_sort.h"
using namespace std;

extern CONF Lab4_read;
int** num_Lab4;
extern int flag_mod = 1;
DATAITEM* tribble;
DATAITEM* Parr;
clock_t start, finish;
double Timesum;

/***********************************************************************
函数名称：use_Arr
函数功能：用二维数组储存数据
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_Arr()
{
	creat_Array(Lab4_read.number);
	if (flag_mod == 1)
	{
		FILE* fp = freopen("D:\\Lab4\\DataSet\\DataFile.txt", "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << num_Lab4[i][j] << ',';
			}
			cout << num_Lab4[i][2] << endl;
		}
		fflush(fp);
		freopen("CON", "w", stdout);
		printf_Arr();
		for (int i = 0; i < Lab4_read.number; i++)
		{
			delete[] num_Lab4[i];
		}
		delete[] num_Lab4;
		printf("已记录数据在默认位置\n");
	}
	else
	{
		string path_of_file;
		printf("请输入储存文件的路径:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			cin >> path_of_file;
		}
		FILE* fp = freopen(path_of_file.data(), "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << num_Lab4[i][j] << ',';
			}
			cout << num_Lab4[i][2] << endl;
		}
		fflush(fp);
		freopen("CON", "w", stdout);
		printf_Arr();
		for (int i = 0; i < Lab4_read.number; i++)
		{
			delete[] num_Lab4[i];
		}
		delete[] num_Lab4;
		printf("已记录数据在特定位置\n");
	}
	return;
}

/***********************************************************************
函数名称：use_Struct
函数功能：用结构体生成数据
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_Struct()
{
	tribble = new DATAITEM[Lab4_read.number];
	//随机生成三元组中元素
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		tribble[i].item1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		tribble[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (tribble[i].item2 == tribble[i].item1)
		{
			tribble[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		tribble[i].item3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
	}
	if (flag_mod == 2)
	{
		string path_of_file;
		printf("请输入储存文件的路径:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			cin >> path_of_file;
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << tribble[i].item1 << ',';
		cout << tribble[i].item2 << ',';
		cout << tribble[i].item1 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf_Struct(tribble);
	delete[] tribble;
}

/***********************************************************************
函数名称：use_pointArr
函数功能: 用指针数组储存数据
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_pointArr()
{
	Parr = new DATAITEM[Lab4_read.number];
	//随机生成三元组中元素
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		Parr[i].item1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		Parr[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (Parr[i].item2 == Parr[i].item1)
		{
			Parr[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		Parr[i].item3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
	}
	if (flag_mod == 2)
	{
		string path_of_file;
		printf("请输入储存文件的路径:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			cin >> path_of_file;
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << Parr[i].item1 << ',';
		cout << Parr[i].item2 << ',';
		cout << Parr[i].item1 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf_Struct(Parr);
	delete[] Parr;
}

/***********************************************************************
函数名称：use_LinkNode
函数功能：用链表储存数据
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_LinkNode()
{
	struct DataNode* head, * node, * end;   		//定义头节点，普通节点，尾节点 
	head = new DataNode[1];							//给头节点申请内存 
	head->nums_data1 = Lab4_read.number;
	end = head;
	node = new DataNode[Lab4_read.number];									//给普通节点申请内存空间 
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		node[i].nums_data1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		node[i].nums_data2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (node[i].nums_data2 == node[i].nums_data1)
		{
			node[i].nums_data2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		node[i].nums_data3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
		end->pNext = &node[i];					    //让上一个节点的数据域指向当前节点 
		end = &node[i];     						//end指向当前节点，最终end指向尾节点 
	}
	end->pNext = NULL;
	if (flag_mod == 2)
	{
		string path_of_file;
		printf("请输入储存文件的路径:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			cin >> path_of_file;
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << node[i].nums_data1 << ',';
		cout << node[i].nums_data2 << ',';
		cout << node[i].nums_data3 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf_DataNode(head);
	delete[] node;
	delete[] head;
	return;
}

/***********************************************************************
函数名称：use_Arr_Lab3
函数功能：运行实验3生成数据并由二维数组储存
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_Arr_Lab3()
{
	creat_Array(Lab4_read.number);
	if (flag_mod == 1)
	{
		char end_path1[100] = {};
		//读取储存在结构体中的地址
		strcat(end_path1, Lab4_read.filename);
		end_path1[strlen(Lab4_read.filename)] = '\\';
		strcat(end_path1, Lab4_read.filesavepath);
		re_call(flag_mod, end_path1, Lab4_read.number);

		int cnt = 0;
		string read_s[100];
		ifstream inf;
		inf.open("D:\\conf.ini");
		if (!inf.is_open())
		{
			cout << "读取文件失败" << endl;
			return;
		}
		while (getline(inf, read_s[cnt]))
		{
			cnt++;
		}
		for (int i = 0; i < read_s[0].length(); i++)
		{
			Lab4_read.filename[i] = read_s[0][i];
		}
		for (int i = 0; i < read_s[1].length(); i++)
		{
			Lab4_read.filesavepath[i] = read_s[1][i];
		}
		Lab4_read.number = changeinto_int_s(read_s[2]);
		Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
		Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
		Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
		Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
		Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
		Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

		FILE* fp = freopen(end_path1, "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << num_Lab4[i][j] << ',';
			}
			cout << num_Lab4[i][2] << endl;
		}
		fflush(fp);
		freopen("CON", "w", stdout);
		printf_Arr();
		for (int i = 0; i < Lab4_read.number; i++)
		{
			delete[] num_Lab4[i];
		}
		delete[] num_Lab4;
		printf("已记录数据在默认位置\n");
	}
	else
	{
		char path_of_file[100];
		if (flag_mod == 2)
		{
			printf("请输入储存文件的路径:\n");
			scanf("%s", path_of_file);
			while (!My_check(path_of_file))
			{
				printf("请输入正确的路径!\n");		//若非法持续输入
				scanf("%s", path_of_file);
			}
			My_find_path(path_of_file);
			ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
			ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
		}
		re_call(flag_mod, path_of_file, Lab4_read.number);

		int cnt = 0;
		string read_s[100];
		ifstream inf;
		inf.open("D:\\conf.ini");
		if (!inf.is_open())
		{
			cout << "读取文件失败" << endl;
			return;
		}
		while (getline(inf, read_s[cnt]))
		{
			cnt++;
		}
		for (int i = 0; i < read_s[0].length(); i++)
		{
			Lab4_read.filename[i] = read_s[0][i];
		}
		for (int i = 0; i < read_s[1].length(); i++)
		{
			Lab4_read.filesavepath[i] = read_s[1][i];
		}
		Lab4_read.number = changeinto_int_s(read_s[2]);
		Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
		Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
		Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
		Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
		Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
		Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

		char end_path1[100] = {};
		//读取储存在结构体中的地址
		strcat(end_path1, Lab4_read.filename);
		end_path1[strlen(Lab4_read.filename)] = '\\';
		strcat(end_path1, Lab4_read.filesavepath);
		FILE* fp = freopen(end_path1, "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << num_Lab4[i][j] << ',';
			}
			cout << num_Lab4[i][2] << endl;
		}
		fflush(fp);
		freopen("CON", "w", stdout);
		printf_Arr();
		for (int i = 0; i < Lab4_read.number; i++)
		{
			delete[] num_Lab4[i];
		}
		delete[] num_Lab4;
		printf("已记录数据在特定位置\n");
	}
	return;
}

/***********************************************************************
函数名称：use_Struct_Lab3
函数功能：运行实验3生成数据并由结构体储存
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_Struct_Lab3()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("请输入储存文件的路径:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	re_call(flag_mod, end_path1, Lab4_read.number);

	int cnt = 0;
	string read_s[100];
	ifstream inf;
	inf.open("D:\\conf.ini");
	if (!inf.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	while (getline(inf, read_s[cnt]))
	{
		cnt++;
	}
	for (int i = 0; i < read_s[0].length(); i++)
	{
		Lab4_read.filename[i] = read_s[0][i];
	}
	for (int i = 0; i < read_s[1].length(); i++)
	{
		Lab4_read.filesavepath[i] = read_s[1][i];
	}
	Lab4_read.number = changeinto_int_s(read_s[2]);
	Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
	Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
	Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
	Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
	Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
	Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

	tribble = new DATAITEM[Lab4_read.number];
	//随机生成三元组中元素
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		tribble[i].item1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		tribble[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (tribble[i].item2 == tribble[i].item1)
		{
			tribble[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		tribble[i].item3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
	}
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << tribble[i].item1 << ',';
		cout << tribble[i].item2 << ',';
		cout << tribble[i].item1 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf_Struct(tribble);
	delete[] tribble;
}

/***********************************************************************
函数名称：use_pointArr_Lab3
函数功能：运行实验3生成数据并由指针数组储存
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_pointArr_Lab3()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("请输入储存文件的路径:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	re_call(flag_mod, end_path1, Lab4_read.number);

	int cnt = 0;
	string read_s[100];
	ifstream inf;
	inf.open("D:\\conf.ini");
	if (!inf.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	while (getline(inf, read_s[cnt]))
	{
		cnt++;
	}
	for (int i = 0; i < read_s[0].length(); i++)
	{
		Lab4_read.filename[i] = read_s[0][i];
	}
	for (int i = 0; i < read_s[1].length(); i++)
	{
		Lab4_read.filesavepath[i] = read_s[1][i];
	}
	Lab4_read.number = changeinto_int_s(read_s[2]);
	Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
	Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
	Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
	Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
	Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
	Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

	Parr = new DATAITEM[Lab4_read.number];
	//随机生成三元组中元素
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		Parr[i].item1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		Parr[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (Parr[i].item2 == Parr[i].item1)
		{
			Parr[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		Parr[i].item3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
	}
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << Parr[i].item1 << ',';
		cout << Parr[i].item2 << ',';
		cout << Parr[i].item1 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf_Struct(Parr);
	delete[] Parr;
}

/***********************************************************************
函数名称：use_LinkNode_Lab3
函数功能：运行实验3生成数据并由链表储存
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_LinkNode_Lab3()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("请输入储存文件的路径:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	re_call(flag_mod, end_path1, Lab4_read.number);

	int cnt = 0;
	string read_s[100];
	ifstream inf;
	inf.open("D:\\conf.ini");
	if (!inf.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	while (getline(inf, read_s[cnt]))
	{
		cnt++;
	}
	for (int i = 0; i < read_s[0].length(); i++)
	{
		Lab4_read.filename[i] = read_s[0][i];
	}
	for (int i = 0; i < read_s[1].length(); i++)
	{
		Lab4_read.filesavepath[i] = read_s[1][i];
	}
	Lab4_read.number = changeinto_int_s(read_s[2]);
	Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
	Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
	Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
	Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
	Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
	Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

	struct DataNode* head, * node, * end;   		//定义头节点，普通节点，尾节点 
	head = new DataNode[1];							//给头节点申请内存 
	head->nums_data1 = Lab4_read.number;
	end = head;
	node = new DataNode[Lab4_read.number];									//给普通节点申请内存空间 
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		node[i].nums_data1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		node[i].nums_data2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (node[i].nums_data1 == node[i].nums_data2)
		{
			node[i].nums_data3 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		node[i].nums_data3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
		end->pNext = &node[i];					    //让上一个节点的数据域指向当前节点 
		end = &node[i];     						//end指向当前节点，最终end指向尾节点 
	}
	end->pNext = NULL;
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << node[i].nums_data1 << ',';
		cout << node[i].nums_data2 << ',';
		cout << node[i].nums_data3 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf_DataNode(head);
	delete[] head;
	delete[] node;
	return;
}

/***********************************************************************
函数名称：use_Arr_Lab3_sort
函数功能: 运行实验3生成数据并由二维数组储存并排序
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_Arr_Lab3_sort()
{
	creat_Array(Lab4_read.number);
	if (flag_mod == 1)
	{
		char end_path1[100] = {};
		//读取储存在结构体中的地址
		strcat(end_path1, Lab4_read.filename);
		end_path1[strlen(Lab4_read.filename)] = '\\';
		strcat(end_path1, Lab4_read.filesavepath);
		re_call(flag_mod, end_path1, Lab4_read.number);

		int cnt = 0;
		string read_s[100];
		ifstream inf;
		inf.open("D:\\conf.ini");
		if (!inf.is_open())
		{
			cout << "读取文件失败" << endl;
			return;
		}
		while (getline(inf, read_s[cnt]))
		{
			cnt++;
		}
		for (int i = 0; i < read_s[0].length(); i++)
		{
			Lab4_read.filename[i] = read_s[0][i];
		}
		for (int i = 0; i < read_s[1].length(); i++)
		{
			Lab4_read.filesavepath[i] = read_s[1][i];
		}
		Lab4_read.number = changeinto_int_s(read_s[2]);
		Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
		Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
		Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
		Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
		Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
		Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

		FILE* fp = freopen("D:\\Lab4\\DataSet\\DataFile.txt", "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << num_Lab4[i][j] << ',';
			}
			cout << num_Lab4[i][2] << endl;
		}
		fflush(fp);
		freopen("CON", "w", stdout);
		int Lab4_sort[100], len = 0;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Lab4_sort[len++] = num_Lab4[i][j];
			}
		}
		printf("排序前:\n");
		printf_Arr();
		start = clock();
		sort(Lab4_sort, Lab4_sort + len, cmp);
		finish = clock();
		Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("共排序%llf秒\n", Timesum);
		printf("排序后\n");
		FILE* fp1 = freopen(end_path1, "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < len; i++)
		{
			printf("%d", Lab4_sort[i]);
			if ((i+1) % 3 == 0)
			{
				printf("\n");
			}
			else
			{
				printf(",");
			}
		}
		fflush(fp1);
		freopen("CON", "w", stdout);
		for (int i = 0; i < len; i++)
		{
			printf("%d", Lab4_sort[i]);
			if ((i+1) % 3 == 0)
			{
				printf("\n");
			}
			else
			{
				printf(",");
			}
		}
		for (int i = 0; i < Lab4_read.number; i++)
		{
			delete[] num_Lab4[i];
		}
		delete[] num_Lab4;
		printf("已记录数据在默认位置并排序\n");
	}
	else
	{
		char path_of_file[100];
		if (flag_mod == 2)
		{
			printf("请输入储存文件的路径:\n");
			scanf("%s", path_of_file);
			while (!My_check(path_of_file))
			{
				printf("请输入正确的路径!\n");		//若非法持续输入
				scanf("%s", path_of_file);
			}
			My_find_path(path_of_file);
			ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
			ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
		}
		re_call(flag_mod, path_of_file, Lab4_read.number);

		int cnt = 0;
		string read_s[100];
		ifstream inf;
		inf.open("D:\\conf.ini");
		if (!inf.is_open())
		{
			cout << "读取文件失败" << endl;
			return;
		}
		while (getline(inf, read_s[cnt]))
		{
			cnt++;
		}
		for (int i = 0; i < read_s[0].length(); i++)
		{
			Lab4_read.filename[i] = read_s[0][i];
		}
		for (int i = 0; i < read_s[1].length(); i++)
		{
			Lab4_read.filesavepath[i] = read_s[1][i];
		}
		Lab4_read.number = changeinto_int_s(read_s[2]);
		Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
		Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
		Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
		Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
		Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
		Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

		char end_path1[100] = {};
		//读取储存在结构体中的地址
		strcat(end_path1, Lab4_read.filename);
		end_path1[strlen(Lab4_read.filename)] = '\\';
		strcat(end_path1, Lab4_read.filesavepath);
		FILE* fp = freopen(end_path1, "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << num_Lab4[i][j] << ',';
			}
			cout << num_Lab4[i][2] << endl;
		}
		fflush(fp);
		freopen("CON", "w", stdout);
		int Lab4_sort[100], len = 0;
		for (int i = 0; i < Lab4_read.number; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Lab4_sort[len++] = num_Lab4[i][j];
			}
		}
		printf("排序前:\n");
		printf_Arr();
		start = clock();
		sort(Lab4_sort, Lab4_sort + len, cmp);
		finish = clock();
		Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("共排序%llf秒\n", Timesum);
		printf("排序后\n");
		FILE* fp1 = freopen(end_path1, "w", stdout);
		cout << Lab4_read.number << endl;
		for (int i = 0; i < len; i++)
		{
			printf("%d", Lab4_sort[i]);
			if ((i+1) % 3 == 0)
			{
				printf("\n");
			}
			else
			{
				printf(",");
			}
		}
		fflush(fp1);
		freopen("CON", "w", stdout);
		for (int i = 0; i < len; i++)
		{
			printf("%d", Lab4_sort[i]);
			if ((i+1) % 3 == 0)
			{
				printf("\n");
			}
			else
			{
				printf(",");
			}
		}
		for (int i = 0; i < Lab4_read.number; i++)
		{
			delete[] num_Lab4[i];
		}
		delete[] num_Lab4;
		printf("已记录数据在特定位置\n");
	}
	return;
}

/***********************************************************************
函数名称：use_Struct_Lab3_sort
函数功能: 运行实验3生成数据并由结构体储存并排序
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_Struct_Lab3_sort()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("请输入储存文件的路径:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	re_call(flag_mod, end_path1, Lab4_read.number);

	int cnt = 0;
	string read_s[100];
	ifstream inf;
	inf.open("D:\\conf.ini");
	if (!inf.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	while (getline(inf, read_s[cnt]))
	{
		cnt++;
	}
	for (int i = 0; i < read_s[0].length(); i++)
	{
		Lab4_read.filename[i] = read_s[0][i];
	}
	for (int i = 0; i < read_s[1].length(); i++)
	{
		Lab4_read.filesavepath[i] = read_s[1][i];
	}
	Lab4_read.number = changeinto_int_s(read_s[2]);
	Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
	Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
	Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
	Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
	Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
	Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

	tribble = new DATAITEM[Lab4_read.number];
	//随机生成三元组中元素
	int Lab4_sort[100], len = 0;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		tribble[i].item1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		tribble[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (tribble[i].item2 == tribble[i].item1)
		{
			tribble[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		tribble[i].item3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
		Lab4_sort[len++] = tribble[i].item1; Lab4_sort[len++] = tribble[i].item2; Lab4_sort[len++] = tribble[i].item3;
	}
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << tribble[i].item1 << ',';
		cout << tribble[i].item2 << ',';
		cout << tribble[i].item1 << endl;
	}
	freopen("CON", "w", stdout);
	printf("排序前:\n");
	printf_Struct(tribble);
	start = clock();
	sort(Lab4_sort, Lab4_sort + len, cmp);
	finish = clock();
	Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("共排序%llf秒\n", Timesum);
	printf("排序后:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d", Lab4_sort[i]);
		if ((i+1) % 3 == 0)printf("\n");
		else
		{
			printf(",");
		}
	}
	delete[] tribble;
}

/***********************************************************************
函数名称：use_pointArr_Lab3_sort
函数功能: 运行实验3生成数据并由指针数组储存并排序
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_pointArr_Lab3_sort()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("请输入储存文件的路径:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	re_call(flag_mod, end_path1, Lab4_read.number);

	int cnt = 0;
	string read_s[100];
	ifstream inf;
	inf.open("D:\\conf.ini");
	if (!inf.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	while (getline(inf, read_s[cnt]))
	{
		cnt++;
	}
	for (int i = 0; i < read_s[0].length(); i++)
	{
		Lab4_read.filename[i] = read_s[0][i];
	}
	for (int i = 0; i < read_s[1].length(); i++)
	{
		Lab4_read.filesavepath[i] = read_s[1][i];
	}
	Lab4_read.number = changeinto_int_s(read_s[2]);
	Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
	Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
	Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
	Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
	Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
	Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

	Parr = new DATAITEM[Lab4_read.number];
	//随机生成三元组中元素
	int Lab4_sort[100], len=0;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		Parr[i].item1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		Parr[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (Parr[i].item2 == Parr[i].item1)
		{
			Parr[i].item2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		Parr[i].item3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
		Lab4_sort[len++] = Parr[i].item1; Lab4_sort[len++] = Parr[i].item2; Lab4_sort[len++] = Parr[i].item3;
	}
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << Parr[i].item1 << ',';
		cout << Parr[i].item2 << ',';
		cout << Parr[i].item1 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf("排序前:\n");
	printf_Struct(Parr);
	start = clock();
	sort(Lab4_sort, Lab4_sort + len, cmp);
	finish = clock();
	Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("共排序%llf秒\n", Timesum);
	printf("排序后\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d", Lab4_sort[i]);
		if ((i+1) % 3 == 0)printf("\n");
		else
		{
			printf(",");
		}
	}
	delete[] Parr;
}

/***********************************************************************
函数名称：use_LinkNode_Lab3_sort
函数功能: 运行实验3生成数据并由链表储存并排序
输入参数：无
返 回 值：无
模块历史：

*************************************************************************/
void use_LinkNode_Lab3_sort()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("请输入储存文件的路径:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("请输入正确的路径!\n");		//若非法持续输入
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//读取储存在结构体中的地址
	strcat(end_path1, Lab4_read.filename);
	end_path1[strlen(Lab4_read.filename)] = '\\';
	strcat(end_path1, Lab4_read.filesavepath);
	re_call(flag_mod, end_path1, Lab4_read.number);

	int cnt = 0;
	string read_s[100];
	ifstream inf;
	inf.open("D:\\conf.ini");
	if (!inf.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	while (getline(inf, read_s[cnt]))
	{
		cnt++;
	}
	for (int i = 0; i < read_s[0].length(); i++)
	{
		Lab4_read.filename[i] = read_s[0][i];
	}
	for (int i = 0; i < read_s[1].length(); i++)
	{
		Lab4_read.filesavepath[i] = read_s[1][i];
	}
	Lab4_read.number = changeinto_int_s(read_s[2]);
	Lab4_read.maxvalue1 = changeinto_int_s(read_s[3]);
	Lab4_read.minvalue1 = changeinto_int_s(read_s[4]);
	Lab4_read.maxvalue2 = changeinto_int_s(read_s[5]);
	Lab4_read.minvalue2 = changeinto_int_s(read_s[6]);
	Lab4_read.recordcount1 = changeinto_int_s(read_s[7]);
	Lab4_read.recordcount2 = changeinto_int_s(read_s[8]);

	struct DataNode* head, * node, * end;   		//定义头节点，普通节点，尾节点 
	head = new DataNode[1];							//给头节点申请内存 
	head->nums_data1 = Lab4_read.number;
	end = head;
	node = new DataNode[Lab4_read.number];									//给普通节点申请内存空间 
	for (int i = 0; i < Lab4_read.number; i++)
	{
		srand((unsigned)time(NULL) + (unsigned)rand());
		node[i].nums_data1 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		node[i].nums_data2 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue2;
		while (node[i].nums_data2 == node[i].nums_data1)
		{
			node[i].nums_data3 = Lab4_read.minvalue1 + rand() % Lab4_read.maxvalue1;
		}
		node[i].nums_data3 = Lab4_read.minvalue2 + rand() % Lab4_read.maxvalue2;
		end->pNext = &node[i];					    //让上一个节点的数据域指向当前节点 
		end = &node[i];     						//end指向当前节点，最终end指向尾节点 
	}
	end->pNext = NULL;
	FILE* fp = freopen(end_path1, "w", stdout);
	cout << Lab4_read.number << endl;
	for (int i = 0; i < Lab4_read.number; i++)
	{
		cout << node[i].nums_data1 << ',';
		cout << node[i].nums_data2 << ',';
		cout << node[i].nums_data3 << endl;
	}
	fflush(fp);
	freopen("CON", "w", stdout);
	printf("排序前:\n");
	printf_DataNode(head);
	start = clock();//程序计时
	Listsort(head);    //排序
	finish = clock();
	Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("排序共计%llf秒\n", Timesum);
	printf("排序后:\n");
	printf_DataNode(head);
	delete[] head;
	delete[] node;
	return;
}