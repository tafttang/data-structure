#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeList.h"

void MergeList_L(Linklist La,Linklist *Lb,Linklist *Lc)
{//指针Lb,Lc要改变，故形参是指向指针的指针 
	Linklist pa,pb,pc;
	
	pa=La->next;
	pb=(*Lb)->next;
	pc=*Lc=La;						//用La的头结点作为Lc的头结点 
	
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next = pa ? pa : pb;	//若pa非空指针就把pa的赋值给pc->next，不然就把pb的值赋给pc->next 
	
	free(*Lb);					//释放Lb的头结点
	*Lb=NULL; 
}

#endif
