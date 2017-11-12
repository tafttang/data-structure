#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "Sequencelist.h"

//�㷨2.3

int InitList_sq(Sqlist *L)
{
	(*L).elem=(LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW);						//�����ڴ�ʧ��	
	(*L).length=0;							//��ʼ��˳�����Ϊ0 
	(*L).listsize=LIST_INIT_SIZE;			//˳����ʼ�ڴ������ 
	return OK;								//��ʼ���ɹ� 
} 
void ClearList_Sq(Sqlist *L)
{
	(*L).length=0;
}

void DestroyList_Sq(Sqlist *L)
{
	free((*L).elem);
	
	(*L).elem=NULL;
	(*L).length=0;
	(*L).listsize=0;
}

int ListEmpty_sq(Sqlist L)
{
	return		L.length==0 ? TRUE : FALSE;
}

int ListLength_sq(Sqlist L)
{
	return L.length;
}

int	GetElem_sq(Sqlist L,int i,LElemType_Sq *e)
{
	if(i<1||i>L.length)
		return ERROR;		//ֵ���Ϸ�
	else
		*e=L.elem[i-1];
	return OK; 
}

//�㷨2.6
int LocateElem_Sq(Sqlist L,LElemType_Sq e,int(Compare)(LElemType_Sq,LElemType_Sq))
{
	int i=1;								//i�ĳ�ֵΪ��һ��Ԫ�ص�λ�� 
	
	while(i<=L.length && !Compare(e,L.elem[i-1]))
		++i;
	if(i<=L.length)
		return i;
	else
		return 0;
} 

int PriorElem_Sq(Sqlist L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
	int i=1;
	
	if(L.elem[0]!=cur_e)
	{
		while(i<L.length&&L.elem[i]!=cur_e)
			++i;
		if(i<L.length)
		{
			*pre_e=L.elem[i-1];
			return OK;
		}
	}
	return ERROR;
}

int NextElem_Sq(Sqlist L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
	int i=0;
	
	while(i<L.length && L.elem[i]!=cur_e)
		++i;
	if(i<L.length-1)
	{
		*next_e=L.elem[i+1];
		return OK;
	}
	return ERROR;
}

//�㷨2.4
int ListInsert_sq(Sqlist *L,int i,LElemType_Sq e)
{
	LElemType_Sq *newbase;
	LElemType_Sq *p,*q;
	
	if(i<1||i>(*L).length+1)
		return ERROR;
	
	if((*L).length >=(*L).listsize)
	{
		newbase =(LElemType_Sq*)realloc((*L).elem,((*L).listsize+LISTINCERMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);
			
		(*L).elem=newbase;
		(*L).listsize += LISTINCERMENT;
	}
	q=&(*L).elem[i-1];
	
	for(p=&(*L).elem[(*L).length-1];p>=q;--p)
		*(p+1)=*p;
		
	*q=e;
	(*L).length++;
	
	return OK;
} 

int ListDelete_sq(Sqlist *L,int i,LElemType_Sq *e)
{
	int j;
	LElemType_Sq *p,*q;
	
	if(i<1||i>(*L).length)
		return ERROR;
		
	p=&(*L).elem[i-1];
	*e=*p;
	q=(*L).elem+(*L).length-1;
	
	for(++p;p<=q;++p)
		*(p-1)=*p;
	(*L).length --;
	
	return OK;
}

int ListTraverse_sq(Sqlist L,void(Visit)(LElemType_Sq))
{
	int i;
	
	for(i=0;i<L.length;i++)
		Visit(L.elem[i]);
		
	return OK;
}

#endif

