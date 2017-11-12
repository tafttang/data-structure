#include<stdio.h>
#include "Union.c"
#include "union.h"

void PrintElem(LElemType_Sq e);

int main(int argc,char **argv)
{
	Sqlist La,Lb;
	LElemType_Sq a[5]={5,2,1,3,9};
	LElemType_Sq b[7]={7,2,6,9,11,3,10};
	int i;
	
	InitList_sq(&La);
	for(i=1;i<=5;i++)
		ListInsert_sq(&La,i,a[i-1]);
	InitList_sq(&Lb);
	for(i=1;i<=7;i++)
		ListInsert_sq(&Lb,i,b[i-1]);
		
	printf("La=");
	ListTraverse_sq(La,PrintElem);
	printf("\n");
	printf("Lb=");
	ListTraverse_sq(Lb,PrintElem);
	printf("\n\n");
	
	printf("La=La¡ÈLb=");
	Union(&La,Lb);
	ListTraverse_sq(La,PrintElem);
	printf("\n\n");
	
	return 0;		
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}

