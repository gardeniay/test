#include<iostream>
#include"Lab4_data.h"
using namespace std;

/***********************************************************************
函数名称：cmp
函数功能: sort函数的排序
输入参数：int a,int b
返 回 值：int
模块历史：

*************************************************************************/
int cmp(int a, int b)
{
    return a < b;
}

/***********************************************************************
函数名称：Linksort
函数功能: 对链表进行排序
输入参数：DataNode*&head
返 回 值：无
模块历史：

*************************************************************************/
void Listsort(DataNode*& head)
{
    int i = 0;
    int m = 0, num;//num是一共要比较的节点数
    //用于变量链表
    m = head->nums_data1;
    /*head = head->next;*/
    //作为一个临时量

    DataNode* p, * q, * tail;
    p = head;//p指向头结点
    for (i = 0; i < m - 1; i++) {
        num = m - i - 1;
        q = head->pNext;//令q指向第一个结点
        p = q->pNext;//令p指向q后一个结点
        tail = head;//让tail始终指向q前一个结点，方便交换，也方便与进行下一步操作
        while (num--) {
            if (q->nums_data3 > p->nums_data3) {
                q->pNext = p->pNext;        //交换节点
                p->pNext = q;
                tail->pNext = p;
            }
            tail = tail->pNext; //都往后移动一位
            q = tail->pNext;
            p = q->pNext;
        }
    }
    return;
}

