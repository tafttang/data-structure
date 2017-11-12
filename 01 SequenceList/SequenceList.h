#ifndef SEQUECELIST_H
#define SEQUECELIST_H
#include <stdio.h>
#include <stdlib.h>				//�ṩmalloc,realloc,free,exit��ԭ�� 
#include "Status.h"

/*�궨��*/ 
#define LIST_INIT_SIZE 100   //˳���洢�ռ�ĳ�ʼ������ 
#define LISTINCERMENT 10	//˳���洢�ռ�ķ������� 

/*˳������Ͷ���*/ 
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ

typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;		//�洢�ռ��ַ 
	int length;				//��ǰ˳����� 
	int listsize;			//��ǰ����Ĵ洢���� 
}Sqlist;					//˳���0�ŵ�Ԫ����ʹ�� 
 
 /*˳������б�*/
int InitList_sq(Sqlist *L);
//(1)�㷨2.3 ��ʼ����˳���L 

void ClearList_Sq(Sqlist *L);
//���˳���L 
 
void DestroyList_Sq(Sqlist *L);
//����˳���L 

int ListEmpty_sq(Sqlist L);
//�ж�˳���L�Ƿ�Ϊ�� 

int ListLength_sq(Sqlist L);
//����˳���L�е�Ԫ�ظ��� 

int GetElem_sq(Sqlist L,int i,LElemType_Sq *e);
//��e����˳���L�еĵ�i��Ԫ�� 

int LocateElem_Sq(Sqlist L,LElemType_Sq e,int(compare)(LElemType_Sq,LElemType_Sq));
//�㷨2.6 ����˳���L���׸���e����compare��ϵ��Ԫ��λ�� 

int PriorElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *pre_e);
//��pre_e����cur_e��ǰ�� 

int NextElem_Sq(Sqlist L,LElemType_Sq cur_e,LElemType_Sq *next_e);
//��next_e����cur_e�ĺ��

int ListInsert_sq(Sqlist *L,int i,LElemType_Sq e);
//�㷨2.4 ��˳���ĵ�i��λ���ϲ���e 

int ListDelete_sq(Sqlist *L,int i,LElemType_Sq *e);
//�㷨2.5 ɾ��˳���L�ϵĵ�i��λ�õ�Ԫ�أ�����e���� 
 
int ListTraverse_sq(Sqlist L,void(Visit)(LElemType_Sq));
//��visit��������˳���L 

#endif

