#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeSqlist.h"

//suanfa2.1
void MergeSqlist_1(Sqlist La,Sqlist Lb,Sqlist *Lc)
{
	int La_len,Lb_len;
	int i,j,k;
	LElemType_Sq ai,bj;
	
	i=j=1;
	k=0;
	
	InitList_sq(Lc);
	La_len=ListLength_sq(La);
	Lb_len=ListLength_sq(Lb);
	
	while(i<=La_len&j<=Lb_len)
	{
		GetElem_sq(La,i,&ai);
		GetElem_sq(Lb,i,&bj);		

		if(ai<=bj)
		{
			ListInsert_sq(Lc,++k,ai);
			i++;
		}
		else
		{
			ListInsert_sq(Lc,++k,bj);
			j++;
		}
	}
	
	while(i<=La_len)
	{
		GetElem_sq(La,i++,&ai);
		ListInsert_sq(Lc,++k,ai);
	}
	while(j<=Lb_len)
	{
		GetElem_sq(Lb,j++,&bj);
		ListInsert_sq(Lc,++k,bj);
	}
}

//suanfa 2.7

void MergeSqlist_2(Sqlist La,Sqlist Lb,Sqlist *Lc)
{
	LElemType_Sq *pa,*pb,*pc;
	LElemType_Sq *pa_last,*pb_last;
	
	pa=La.elem;
	pb=Lb.elem;
	
	(*Lc).listsize=(*Lc).length =La.length+Lb.length;
	pc=(*Lc).elem=(LElemType_Sq *)malloc((*Lc).listsize*sizeof(LElemType_Sq));
	if(!pc)
	exit(OVERFLOW);
	
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	
	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa<=*pb)
			*pc++-*pa++;
		else
			*pc++=*pb++;
	}
	while(pa <= pa_last)
		*pc++-*pa++;
	while(pb <= pb_last)
		*pc++=*pb++;
}

#endif

