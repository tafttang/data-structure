#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../00 xulun/Status.h"
#include "../00 xulun/Scanf.c"

/*���������Ͷ���*/
#ifndef BANKQUEUING_H
typedef int LElemtype_L;


/*������ṹ��*/
typedef struct LNode
{
	LElemtype_L data;
	struct LNode* next;
}LNode;
typedef LNode* Linklist;
#endif

/*��������ͷ��㣩�����б�*/
int InitList_L(Linklist *L);

int ClearList_L(Linklist L);

void DestroyList_L(Linklist *L);

int ListEmpty_L(Linklist L);

int ListLength_L(Linklist L);

int GetElem_L(Linklist L,int i, LElemtype_L *e);
//��e���յ�����L�еĵ�i��Ԫ��

int LocateElem_L(Linklist L,LElemtype_L e,int(compare)(LElemtype_L,LElemtype_L));
//���ص�����L�е�һ����e����compare��ϵ��Ԫ��λ�� 

int PriorElem_L(Linklist L,LElemtype_L cur_e,LElemtype_L *pre_e);

int NextElem_L(Linklist L,LElemtype_L cur_e,LElemtype_L *next_e);

int ListInsert_L(Linklist L,int i,LElemtype_L e);

int ListDelete_L(Linklist L,int i,LElemtype_L *e);

int ListTraverse_L(Linklist L,void(Visit)(LElemtype_L));

int CreateList_HL(FILE *fp,Linklist *L,int n);
//�㷨2.11 ͷ���뷨����������L �������� 
int CreateList_TL(FILE *fp,Linklist *L,int n);
//β���뷨����������L ��˳�����룩 
 
#endif
