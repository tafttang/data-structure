#ifndef	DUALCYCLELINKEDLISTT_H
#define DUALCYCLELINKEDLIST_H

#include <stdlib.h>
#include "../00 xulun/Status.h"

/*双循环链表类型定义*/
typedef int LElemType_DC;
typedef struct DulNode
{
	LElemType_DC data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode;
typedef DulNode* DuLinklist;			//指向双循环链表结构的指针

/*双循环链表函数列表*/

//(01)初始化双链表L
int InitList_DuL(DuLinklist *L);

//(02)置空L 
int ClearList_DuL(DuLinklist L);

//(03)销毁L
void DestroyList_DuL(DuLinklist *L);

//(04)判断L是否为空
int ListEmpty_DuL(DuLinklist L);

//(05)返回L元素个数
int ListLength_DuL(DuLinklist L);

//(06)用e接受L中第i个结点的元素值
int GetElem_DuL(DuLinklist L,int i,LElemType_DC *e);

//(07)返回L中第一个与e满足compare关系的元素位序
int LocateElem_DuL(DuLinklist L,LElemType_DC e,int(compare)(LElemType_DC,LElemType_DC));

//(08)用pre_e接收cur_e的前驱
int PriorElem_DuL(DuLinklist L,LElemType_DC cur_e,LElemType_DC *pre_e);

//(09)用next_e接收cur_e的后继
int NextElem_DuL(DuLinklist L,LElemType_DC cur_e,LElemType_DC *next_e);

//(10)返回L中指向第i个结点的指针
DuLinklist GetElemPtr_DuL(DuLinklist L,int i);

//(11)在L第i个位置之前插入e
int ListInsert_Dul(DuLinklist L,int i,LElemType_DC e);

//(12)删除L第i个位置的值，并用e接收
int ListDelete_DuL(DuLinklist L,int i,LElemType_DC *e);

//(13)用Visit函数访问L 
void ListTraverse_DuL(DuLinklist L,void(Visit)(LElemType_DC));

#endif
