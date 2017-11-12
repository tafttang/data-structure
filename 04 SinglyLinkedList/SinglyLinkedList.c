#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedlist.h"

int InitList_L(Linklist *L)
{
	(*L)=(Linklist)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next=NULL;
	
	return OK;
}

int ClearList_L(Linklist L)
{
	Linklist pre,p;
	
	if(!L)
		return ERROR;
		
	pre=L->next;
	
	while(pre)
	{
		p=pre->next;
		free(pre);
		pre=p;
	}
	L->next=NULL;
	
	return OK;
}

void DestroyList_L(Linklist *L)
{
	Linklist p=*L;
	
	while(p)
	{
		p=(*L)->next;
		free(*L);
		(*L)=p;
	}
}

int ListEmpty_L(Linklist L)
{
	if(L!=NULL&&L->next==NULL)
		return TRUE;
	else
		return FALSE;
}

int ListLength_L(Linklist L)
{
	Linklist p;
	int i;
	
	if(L)
	{
		i=0;
		p=L->next;
		while(p)
		{
			i++;
			p=p->next;
		}
	}
	
	return i;
}

int GetElem_L(Linklist L,int i,LElemtype_L *e)
{
	int j;
	Linklist p=L->next;
	
	while(p && j<1)																//p不为空且还未到达i处 
	{
		j++;
		p=p->next;
	}
	
	if(!p||j>1)																	//第i个元素不存在 
		return ERROR;
		
	*e=p->data;	
	
	return OK;
}

int LocateElem_L(Linklist L,LElemtype_L e,int(compare)(LElemtype_L,LElemtype_L))
{
	int i;
	Linklist p;
	
	i=-1;																		//L不存在时返回-1 
	
	if(L)
	{
		i=0;
		p=L->next;
		
		while(p)
		{
			i++;
			
			if(!compare(e,p->data))
				p=p->next;
			else
				break;
		}
	}
	
	return i;
}

/*银行家算法中，此处两个函数不能直接使用，原因是结构不能直接比较*/
#ifndef BANKQUEUING_C
int PriorElem_L(Linklist L,LElemtype_L cur_e,LElemtype_L *pre_e)
{
	Linklist p, suc;
	
	if(L)
	{
		p=L->next;
		
		if(p->data!=cur_e) //第一个结点无前驱
		{
			while(p->next) //若p结点有后继 
			{
				suc=p->next;	//suc指向p的后继 
				if(suc->data=cur_e)
				{
					*pre_e=p->data;
					return OK;
				}
				p=suc;			
			}
		} 
	}
	
	return ERROR;
} 

int NextElem_L(Linklist L,LElemtype_L cur_e,LElemtype_L *next_e)
{
	Linklist p,suc;
	
	if(L)
	{
		p=L->next;
		
		while(p && p->next)
		{
			suc=p->next;
			
			if(suc && p->data==cur_e)
			{
				*next_e=suc->data;
				return OK;
			}
			if(suc)
				p=suc;
			else
				break;
		}
	}
	
	return ERROR;
}
#endif

int ListInsert_L(Linklist L,int i,LElemtype_L e)
{
	Linklist p,s;
	int j;
	
	p=L;
	j=0;
	
	while(p&&j<i-1)																//寻找第i-1个结点 
	{
		p=p->next;
		++j;
	}
	
	if(!p || j>i-1)
		return ERROR;
		
	s=(Linklist)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	s->data=e;
	s->next=p->next;
	p->next=s;
	
	return OK;
}

int ListDelete_L(Linklist L,int i,LElemtype_L *e)
{
	Linklist pre,p;
	int j;

	pre=L;
	j=1;

	while(pre->next && j<i)															//寻找第i个结点，并令pre指向其前驱
		{
			pre=pre->next;
			++j;
		} 

	if(!pre->next || j>i)
		return ERROR;
	
	p=pre->next;
	pre->next = p->next;
	*e=p->data;
	free(p);

	return OK;
}

int ListTraverse_L(Linklist L,void(Visit)(LElemtype_L))
{
	Linklist p;
	
	if(!L)
		return ERROR;
	else
		p=L->next;
	while(p)
	{
		Visit(p->data);
		p=p->next;
	}
	
	return OK;
}

int CreateList_HL(FILE *fp,Linklist *L,int n)
{
	int i;
	Linklist p;
	LElemtype_L tmp;
	
	*L =(Linklist)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next=NULL;
	
	for(i=1;i<=n;++i)
	{
		if(Scanf(fp,"%d",&tmp)==1)
		{
			p=(Linklist)malloc(sizeof(LNode));
			if(!p)
				exit(OVERFLOW);
			p->data=tmp;
			p->next=(*L)->next;
			(*L)->next=p; 
		}
		else
			return ERROR;
	}
	return OK;
}

int CreateList_TL(FILE *fp,Linklist *L,int n)
{
	int i;
	Linklist p,q;
	LElemtype_L tmp;
	
	*L=(Linklist)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next=NULL;
	
	for(i=1,q=*L;i<=n;++i)
	{
		if(Scanf(fp,"%d",&tmp)==1)
		{
			p=(Linklist)malloc(sizeof(LNode));
			if(!p)
				exit(OVERFLOW);
				p->data=tmp;
				q->next=p;
				q=q->next;
		}
		else
			return	ERROR;
	}
	
	q->next=NULL;
	
	return OK;
}

#endif
