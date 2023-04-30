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
�������ƣ�use_Arr
�������ܣ��ö�ά���鴢������
�����������
�� �� ֵ����
ģ����ʷ��

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
		printf("�Ѽ�¼������Ĭ��λ��\n");
	}
	else
	{
		string path_of_file;
		printf("�����봢���ļ���·��:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
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
		printf("�Ѽ�¼�������ض�λ��\n");
	}
	return;
}

/***********************************************************************
�������ƣ�use_Struct
�������ܣ��ýṹ����������
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_Struct()
{
	tribble = new DATAITEM[Lab4_read.number];
	//���������Ԫ����Ԫ��
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
		printf("�����봢���ļ���·��:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			cin >> path_of_file;
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
�������ƣ�use_pointArr
��������: ��ָ�����鴢������
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_pointArr()
{
	Parr = new DATAITEM[Lab4_read.number];
	//���������Ԫ����Ԫ��
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
		printf("�����봢���ļ���·��:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			cin >> path_of_file;
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
�������ƣ�use_LinkNode
�������ܣ�������������
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_LinkNode()
{
	struct DataNode* head, * node, * end;   		//����ͷ�ڵ㣬��ͨ�ڵ㣬β�ڵ� 
	head = new DataNode[1];							//��ͷ�ڵ������ڴ� 
	head->nums_data1 = Lab4_read.number;
	end = head;
	node = new DataNode[Lab4_read.number];									//����ͨ�ڵ������ڴ�ռ� 
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
		end->pNext = &node[i];					    //����һ���ڵ��������ָ��ǰ�ڵ� 
		end = &node[i];     						//endָ��ǰ�ڵ㣬����endָ��β�ڵ� 
	}
	end->pNext = NULL;
	if (flag_mod == 2)
	{
		string path_of_file;
		printf("�����봢���ļ���·��:\n");
		cin >> path_of_file;
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			cin >> path_of_file;
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
�������ƣ�use_Arr_Lab3
�������ܣ�����ʵ��3�������ݲ��ɶ�ά���鴢��
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_Arr_Lab3()
{
	creat_Array(Lab4_read.number);
	if (flag_mod == 1)
	{
		char end_path1[100] = {};
		//��ȡ�����ڽṹ���еĵ�ַ
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
			cout << "��ȡ�ļ�ʧ��" << endl;
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
		printf("�Ѽ�¼������Ĭ��λ��\n");
	}
	else
	{
		char path_of_file[100];
		if (flag_mod == 2)
		{
			printf("�����봢���ļ���·��:\n");
			scanf("%s", path_of_file);
			while (!My_check(path_of_file))
			{
				printf("��������ȷ��·��!\n");		//���Ƿ���������
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
			cout << "��ȡ�ļ�ʧ��" << endl;
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
		//��ȡ�����ڽṹ���еĵ�ַ
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
		printf("�Ѽ�¼�������ض�λ��\n");
	}
	return;
}

/***********************************************************************
�������ƣ�use_Struct_Lab3
�������ܣ�����ʵ��3�������ݲ��ɽṹ�崢��
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_Struct_Lab3()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("�����봢���ļ���·��:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
		cout << "��ȡ�ļ�ʧ��" << endl;
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
	//���������Ԫ����Ԫ��
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
�������ƣ�use_pointArr_Lab3
�������ܣ�����ʵ��3�������ݲ���ָ�����鴢��
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_pointArr_Lab3()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("�����봢���ļ���·��:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
		cout << "��ȡ�ļ�ʧ��" << endl;
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
	//���������Ԫ����Ԫ��
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
�������ƣ�use_LinkNode_Lab3
�������ܣ�����ʵ��3�������ݲ���������
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_LinkNode_Lab3()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("�����봢���ļ���·��:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
		cout << "��ȡ�ļ�ʧ��" << endl;
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

	struct DataNode* head, * node, * end;   		//����ͷ�ڵ㣬��ͨ�ڵ㣬β�ڵ� 
	head = new DataNode[1];							//��ͷ�ڵ������ڴ� 
	head->nums_data1 = Lab4_read.number;
	end = head;
	node = new DataNode[Lab4_read.number];									//����ͨ�ڵ������ڴ�ռ� 
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
		end->pNext = &node[i];					    //����һ���ڵ��������ָ��ǰ�ڵ� 
		end = &node[i];     						//endָ��ǰ�ڵ㣬����endָ��β�ڵ� 
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
�������ƣ�use_Arr_Lab3_sort
��������: ����ʵ��3�������ݲ��ɶ�ά���鴢�沢����
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_Arr_Lab3_sort()
{
	creat_Array(Lab4_read.number);
	if (flag_mod == 1)
	{
		char end_path1[100] = {};
		//��ȡ�����ڽṹ���еĵ�ַ
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
			cout << "��ȡ�ļ�ʧ��" << endl;
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
		printf("����ǰ:\n");
		printf_Arr();
		start = clock();
		sort(Lab4_sort, Lab4_sort + len, cmp);
		finish = clock();
		Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("������%llf��\n", Timesum);
		printf("�����\n");
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
		printf("�Ѽ�¼������Ĭ��λ�ò�����\n");
	}
	else
	{
		char path_of_file[100];
		if (flag_mod == 2)
		{
			printf("�����봢���ļ���·��:\n");
			scanf("%s", path_of_file);
			while (!My_check(path_of_file))
			{
				printf("��������ȷ��·��!\n");		//���Ƿ���������
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
			cout << "��ȡ�ļ�ʧ��" << endl;
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
		//��ȡ�����ڽṹ���еĵ�ַ
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
		printf("����ǰ:\n");
		printf_Arr();
		start = clock();
		sort(Lab4_sort, Lab4_sort + len, cmp);
		finish = clock();
		Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("������%llf��\n", Timesum);
		printf("�����\n");
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
		printf("�Ѽ�¼�������ض�λ��\n");
	}
	return;
}

/***********************************************************************
�������ƣ�use_Struct_Lab3_sort
��������: ����ʵ��3�������ݲ��ɽṹ�崢�沢����
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_Struct_Lab3_sort()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("�����봢���ļ���·��:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
		cout << "��ȡ�ļ�ʧ��" << endl;
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
	//���������Ԫ����Ԫ��
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
	printf("����ǰ:\n");
	printf_Struct(tribble);
	start = clock();
	sort(Lab4_sort, Lab4_sort + len, cmp);
	finish = clock();
	Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("������%llf��\n", Timesum);
	printf("�����:\n");
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
�������ƣ�use_pointArr_Lab3_sort
��������: ����ʵ��3�������ݲ���ָ�����鴢�沢����
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_pointArr_Lab3_sort()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("�����봢���ļ���·��:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
		cout << "��ȡ�ļ�ʧ��" << endl;
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
	//���������Ԫ����Ԫ��
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
	printf("����ǰ:\n");
	printf_Struct(Parr);
	start = clock();
	sort(Lab4_sort, Lab4_sort + len, cmp);
	finish = clock();
	Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("������%llf��\n", Timesum);
	printf("�����\n");
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
�������ƣ�use_LinkNode_Lab3_sort
��������: ����ʵ��3�������ݲ��������沢����
�����������
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void use_LinkNode_Lab3_sort()
{
	char path_of_file[100];
	if (flag_mod == 2)
	{
		printf("�����봢���ļ���·��:\n");
		scanf("%s", path_of_file);
		while (!My_check(path_of_file))
		{
			printf("��������ȷ��·��!\n");		//���Ƿ���������
			scanf("%s", path_of_file);
		}
		My_find_path(path_of_file);
		ModifyLineData("D:\\conf.ini", 1, Lab4_read.filename);
		ModifyLineData("D:\\conf.ini", 2, Lab4_read.filesavepath);
	}
	char end_path1[100] = {};
	//��ȡ�����ڽṹ���еĵ�ַ
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
		cout << "��ȡ�ļ�ʧ��" << endl;
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

	struct DataNode* head, * node, * end;   		//����ͷ�ڵ㣬��ͨ�ڵ㣬β�ڵ� 
	head = new DataNode[1];							//��ͷ�ڵ������ڴ� 
	head->nums_data1 = Lab4_read.number;
	end = head;
	node = new DataNode[Lab4_read.number];									//����ͨ�ڵ������ڴ�ռ� 
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
		end->pNext = &node[i];					    //����һ���ڵ��������ָ��ǰ�ڵ� 
		end = &node[i];     						//endָ��ǰ�ڵ㣬����endָ��β�ڵ� 
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
	printf("����ǰ:\n");
	printf_DataNode(head);
	start = clock();//�����ʱ
	Listsort(head);    //����
	finish = clock();
	Timesum = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("���򹲼�%llf��\n", Timesum);
	printf("�����:\n");
	printf_DataNode(head);
	delete[] head;
	delete[] node;
	return;
}