#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>
#include "../00 xulun/Status.h"

#define MAXSIZE 1000

/*��̬�������Ͷ���*/
typedef int SLinkList;		//��̬�������� 
typedef int LElemType_S;
typedef struct
{
	LElemType_S data;
	int cur;			//cur���α꣬��ָ���ã������������±� 
}Component[MAXSIZE];	//����ռ����� 

/*ȫ�ֱ���*/
Component SPACE;		//��̬����ռ�

/*��̬�������б�*/

//�㷨2.14 ��һά����SPACE�и���������һ����ı��ÿռ�
void InitSpace_SL();

//�㷨2.15 Ϊ������������ռ�
int Malloc_SL();

//�㷨2.16 ���±�Ϊk�Ŀ��н�����
void Free_SL();

//��ʼ����̬��������ͷ���
int InitList_SL(SLinkList *H);

//�ÿ�
int ClearList_SL(SLinkList H);

//����
void DestroyList_SL(SLinkList *H);

//�п�
int ListEmpty_SL(SLinkList H);

//��
int ListLength_SL(SLinkList H);

//ȡֵ
int GetElem_SL(SLinkList H,int i,LElemType_S *e);

//����Ԫ��e��λ��
int LocateElem_SL(SLinkList H,LElemType_S e);

//ǰ��
int PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e); 

//���
int NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e);

//����
int ListInsert_SL(SLinkList H,int i,LElemType_S e);

//ɾ��
int ListDelete_SL(SLinkList H,int i,LElemType_S *e);

//����
int ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S));

#endif
