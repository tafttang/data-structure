#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>
#include "../00 xulun/Status.h"

#define MAXSIZE 1000

/*静态链表类型定义*/
typedef int SLinkList;		//静态链表类型 
typedef int LElemType_S;
typedef struct
{
	LElemType_S data;
	int cur;			//cur是游标，做指针用，区别于数组下标 
}Component[MAXSIZE];	//链表空间类型 

/*全局变量*/
Component SPACE;		//静态链表空间

/*静态链表函数列表*/

//算法2.14 将一维数组SPACE中各分量链成一个大的备用空间
void InitSpace_SL();

//算法2.15 为插入数据申请空间
int Malloc_SL();

//算法2.16 将下标为k的空闲结点回收
void Free_SL();

//初始化静态链表，建立头结点
int InitList_SL(SLinkList *H);

//置空
int ClearList_SL(SLinkList H);

//销毁
void DestroyList_SL(SLinkList *H);

//判空
int ListEmpty_SL(SLinkList H);

//求长
int ListLength_SL(SLinkList H);

//取值
int GetElem_SL(SLinkList H,int i,LElemType_S *e);

//返回元素e的位序
int LocateElem_SL(SLinkList H,LElemType_S e);

//前驱
int PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e); 

//后继
int NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e);

//插入
int ListInsert_SL(SLinkList H,int i,LElemType_S e);

//删除
int ListDelete_SL(SLinkList H,int i,LElemType_S *e);

//访问
int ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S));

#endif
