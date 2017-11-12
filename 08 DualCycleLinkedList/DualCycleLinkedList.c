#ifndef DUALCYCLELINKEDLIST_C
#define DUALCYCLELINKEDLIST_C

#include "DualCycleLinkedList.h"

int InitList_DuL(DuLinklist *L)
{
	*L = (DuLinklist)malloc(sizeof(DulNode));
	if(!(*L))
		exit(OVERFLOW);
		
	(*L)->next = (*L)->prior = *L;
	
	return OK;
}

int ClearList_DuL(DuLinklist L)
{
	DuLinklist p,q;
	
	p = L->next;
	
	while(p!=L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	L->next = L->prior = L;
	
	return OK;	
}

void DestroyList_DuL(DuLinklist *L)
{
	ClearList_DuL(*L);
	free(*L);
	*L = NULL;
}

int ListEmpty_DuL(DuLinklist L)
{
	if(L && L->next == L && L->prior == L)
		return TRUE;
	else
		return FALSE;
}

int ListLength_DuL(DuLinklist L)
{
	DuLinklist p;
	int count;
	
	if(L)
	{
		count = 0;
		p = L ;
		
		while(p->next!=L)
		{
			count++;
			p = p->next;
		}
	}
	
	return count;
}

int GetElem_DuL(DuLinklist L,int i,LElemType_DC *e)
{
	DuLinklist p;
	int count;
	
	if(L)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && count<i)
		{
			count++;
			p = p->next;
		}
		
		if(p!=L)
		{
			*e = p->data;
			return OK;
		}
	}
	
	return ERROR;
}

int LocateElem_DuL(DuLinklist L,LElemType_DC e,int(Compare)(LElemType_DC,LElemType_DC))
{
	DuLinklist p;
	int count;
	
	if(L)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && !Compare(e,p->data))
		{
			count++;
			p = p->next;
		}
		
		if(p!=L)
			return count;
	}
	
	return 0;
}

int PriorElem_DuL(DuLinklist L,LElemType_DC cur_e,LElemType_DC *pre_e)
{
	DuLinklist p;
	
	if(L)
	{
		p = L->next;
		
		while(p!=L && p->data!=cur_e)
			p = p->next;
			
		if(p!=L && p->prior!=L)			//p不为首结点 
		{
			*pre_e = p->prior->data;
			return OK;
		}
	}
	
	return ERROR;
}

int NextElem_DuL(DuLinklist L,LElemType_DC cur_e,LElemType_DC *next_e)
{
	DuLinklist p;
	
	if(L)
	{
		p = L->next;
		
		while(p!=L && p->data!=cur_e)
			p = p->next;
		
		if(p!=L && p->next!=L)
		{
			*next_e = p->next->data;
			return OK;
		}
	}
	
	return ERROR;
}

DuLinklist GetElemPtr_DuL(DuLinklist L,int i)
{
	int count;
	DuLinklist p;
	
	if(L && i>0)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && count<i)
		{
			count++;
			p = p->next;
		}
		
		if(p!=L)
			return p;
	}
	
	return NULL;
}

//与课本双链表插入算法略有不同，根源在于GetElemP_Dul不同 */ 
int ListInsert_Dul(DuLinklist L,int i,LElemType_DC e)
{
	DuLinklist p,s;
	
	if(i<1 || i>ListLength_DuL(L)+1)
		return ERROR;
	
	p = GetElemPtr_DuL(L,i);
	if(!p)
		p = L;
	
	s = (DuLinklist)malloc(sizeof(DulNode));
	if(!s)
		exit(OVERFLOW);
	s->data = e;
	
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	
	return OK;
}

int ListDelete_DuL(DuLinklist L,int i,LElemType_DC *e)
{
	DuLinklist p;
	
	if(!(p=GetElemPtr_DuL(L,i))) 	//i值不合法 
		return ERROR;
		
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	
	free(p);
	p = NULL;
	
	return OK;
}

void ListTraverse_DuL(DuLinklist L,void(Visit)(LElemType_DC))
{
	DuLinklist p;
	
	p = L->next;
	
	while(p!=L)
	{
		Visit(p->data);
		p = p->next;
	}
}

#endif
