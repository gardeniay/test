#include<iostream>
#include"Lab4_data.h"
using namespace std;

/***********************************************************************
�������ƣ�cmp
��������: sort����������
���������int a,int b
�� �� ֵ��int
ģ����ʷ��

*************************************************************************/
int cmp(int a, int b)
{
    return a < b;
}

/***********************************************************************
�������ƣ�Linksort
��������: �������������
���������DataNode*&head
�� �� ֵ����
ģ����ʷ��

*************************************************************************/
void Listsort(DataNode*& head)
{
    int i = 0;
    int m = 0, num;//num��һ��Ҫ�ȽϵĽڵ���
    //���ڱ�������
    m = head->nums_data1;
    /*head = head->next;*/
    //��Ϊһ����ʱ��

    DataNode* p, * q, * tail;
    p = head;//pָ��ͷ���
    for (i = 0; i < m - 1; i++) {
        num = m - i - 1;
        q = head->pNext;//��qָ���һ�����
        p = q->pNext;//��pָ��q��һ�����
        tail = head;//��tailʼ��ָ��qǰһ����㣬���㽻����Ҳ�����������һ������
        while (num--) {
            if (q->nums_data3 > p->nums_data3) {
                q->pNext = p->pNext;        //�����ڵ�
                p->pNext = q;
                tail->pNext = p;
            }
            tail = tail->pNext; //�������ƶ�һλ
            q = tail->pNext;
            p = q->pNext;
        }
    }
    return;
}

