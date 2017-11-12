#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../00 xulun/Status.h"
#include "../00 xulun/Scanf.c"

/*单链表类型定义*/
#ifndef BANKQUEUING_H
typedef int LElemtype_L;


/*单链表结构体*/
typedef struct LNode
{
	LElemtype_L data;
	struct LNode* next;
}LNode;
typedef LNode* Linklist;
#endif

/*单链表（带头结点）函数列表*/
int InitList_L(Linklist *L);

int ClearList_L(Linklist L);

void DestroyList_L(Linklist *L);

int ListEmpty_L(Linklist L);

int ListLength_L(Linklist L);

int GetElem_L(Linklist L,int i, LElemtype_L *e);
//用e接收单链表L中的第i个元素

int LocateElem_L(Linklist L,LElemtype_L e,int(compare)(LElemtype_L,LElemtype_L));
//返回单链表L中第一个与e满足compare关系的元素位序 

int PriorElem_L(Linklist L,LElemtype_L cur_e,LElemtype_L *pre_e);

int NextElem_L(Linklist L,LElemtype_L cur_e,LElemtype_L *next_e);

int ListInsert_L(Linklist L,int i,LElemtype_L e);

int ListDelete_L(Linklist L,int i,LElemtype_L *e);

int ListTraverse_L(Linklist L,void(Visit)(LElemtype_L));

int CreateList_HL(FILE *fp,Linklist *L,int n);
//算法2.11 头插入法建立单链表L 逆序输入 
int CreateList_TL(FILE *fp,Linklist *L,int n);
//尾插入法建立单链表L （顺序输入） 
 
#endif
