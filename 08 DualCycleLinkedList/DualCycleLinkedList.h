#ifndef	DUALCYCLELINKEDLISTT_H
#define DUALCYCLELINKEDLIST_H

#include <stdlib.h>
#include "../00 xulun/Status.h"

/*˫ѭ���������Ͷ���*/
typedef int LElemType_DC;
typedef struct DulNode
{
	LElemType_DC data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode;
typedef DulNode* DuLinklist;			//ָ��˫ѭ������ṹ��ָ��

/*˫ѭ���������б�*/

//(01)��ʼ��˫����L
int InitList_DuL(DuLinklist *L);

//(02)�ÿ�L 
int ClearList_DuL(DuLinklist L);

//(03)����L
void DestroyList_DuL(DuLinklist *L);

//(04)�ж�L�Ƿ�Ϊ��
int ListEmpty_DuL(DuLinklist L);

//(05)����LԪ�ظ���
int ListLength_DuL(DuLinklist L);

//(06)��e����L�е�i������Ԫ��ֵ
int GetElem_DuL(DuLinklist L,int i,LElemType_DC *e);

//(07)����L�е�һ����e����compare��ϵ��Ԫ��λ��
int LocateElem_DuL(DuLinklist L,LElemType_DC e,int(compare)(LElemType_DC,LElemType_DC));

//(08)��pre_e����cur_e��ǰ��
int PriorElem_DuL(DuLinklist L,LElemType_DC cur_e,LElemType_DC *pre_e);

//(09)��next_e����cur_e�ĺ��
int NextElem_DuL(DuLinklist L,LElemType_DC cur_e,LElemType_DC *next_e);

//(10)����L��ָ���i������ָ��
DuLinklist GetElemPtr_DuL(DuLinklist L,int i);

//(11)��L��i��λ��֮ǰ����e
int ListInsert_Dul(DuLinklist L,int i,LElemType_DC e);

//(12)ɾ��L��i��λ�õ�ֵ������e����
int ListDelete_DuL(DuLinklist L,int i,LElemType_DC *e);

//(13)��Visit��������L 
void ListTraverse_DuL(DuLinklist L,void(Visit)(LElemType_DC));

#endif
