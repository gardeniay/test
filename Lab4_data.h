#ifndef LAB4_LAB4_DATA_H
#define LAB4_LAB4_DATA_H

const int MAX_STR_LEN = 100;
typedef  struct  configinfo {
	char  filesavepath[MAX_STR_LEN];     	//用于存放数据记录文件的存储目录
	char  filename[MAX_STR_LEN];              //用于存储数据记录文件的文件名信息
	int  number;		//用于存放生成的记录条数
	int  maxvalue1;   		//用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
	int  minvalue1; 		//用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
	int  maxvalue2;   		//用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
	int  minvalue2; 		//用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
	int  recordcount1;	//用于存放数据记录文件需要随机生成记录条数时条数值的上限
	int  recordcount2;	//用于存放数据记录文件需要随机生成记录条数时条数值的下限
} CONF;

typedef  struct  DataItem {
	int  item1;     //数据记录三元组第一个元素
	int  item2;     //数据记录三元组第二个元素
	int  item3;     //数据记录三元组第三个元素
} DATAITEM;

typedef struct DataNode		//链表
{
	int nums_data1, nums_data2, nums_data3;			//储存的数据
	DataNode* pNext;
}DN;

#endif
