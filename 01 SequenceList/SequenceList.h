#ifndef SEQUECELIST_H
#define SEQUECELIST_H
#include <stdio.h>
#include <stdlib.h>				//提供malloc,realloc,free,exit等原型 
#include "Status.h"

/*宏定义*/ 
#define LIST_INIT_SIZE 100   //顺序表存储空间的初始分配量 
#define LISTINCERMENT 10	//顺序表存储空间的分配增量 

/*顺序表类型定义*/ 
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ

typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;		//存储空间基址 
	int length;				//当前顺序表长度 
	int listsize;			//当前分配的存储容量 
}Sqlist;					//顺序表0号单元正常使用 
 
 /*顺序表函数列表*/
int InitList_sq(Sqlist *L);
//(1)算法2.3 初始化空顺序表L 

void ClearList_Sq(Sqlist *L);
//清空顺序表L 
 
void DestroyList_Sq(Sqlist *L);
//销毁顺序表L 

int ListEmpty_sq(Sqlist L);
//判断顺序表L是否为空 

int ListLength_sq(Sqlist L);
//返回顺序表L中的元素个数 

int GetElem_sq(Sqlist L,int i,LElemType_Sq *e);
//用e接收顺序表L中的第i个元素 

int LocateElem_Sq(Sqlist L,LElemType_Sq e,int(compare)(LElemType_Sq,LElemType_Sq));
//算法2.6 返回顺序表L中首个与e满足compare关系的元素位序 

int PriorElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *pre_e);
//用pre_e接收cur_e的前驱 

int NextElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *next_e);
//用next_e接收cur_e的后继

int ListInsert_sq(Sqlist *L,int i,LElemType_Sq e);
//算法2.4 在顺序表的第i个位置上插入e 

int ListDelete_sq(Sqlist *L,int i,LElemType_Sq *e);
//算法2.5 删除顺序表L上的第i个位置的元素，并用e返回 
 
int ListTraverse_sq(Sqlist L,void(Visit)(LElemType_Sq));
//用visit函数访问顺序表L 

#endif

