#ifndef UNION_C
#define UNION_C

#include "Union.h"

void Union(Sqlist *La,Sqlist Lb)
{
	int La_len,Lb_len;
	int i;
	LElemType_Sq e;
	
	La_len=ListLength_sq(*La);
	Lb_len=ListLength_sq(Lb);
	
	for(i=1;i<=Lb_len;i++)
	{
		GetElem_sq(Lb,i,&e);
		if(!LocateElem_Sq(*La,e,equal))
			ListInsert_sq(La,++La_len,e);
	}
}

int equal(LElemType_Sq e1,LElemType_Sq e2)
{
	return e1==e2 ? TRUE : FALSE;	
}

#endif

