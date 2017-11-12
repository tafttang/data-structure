#include <stdio.h>
#include "MergeSqlist.c"

void PrintElem(LElemType_Sq e);

int main(int argc,char **argv)
{
	Sqlist La,Lb,Lc1,Lc2;
	LElemType_Sq a[4]={3,5,8,11};
	LElemType_Sq b[7]={2,6,8,9,11,15,20};
	int i;
	
	InitList_sq(&La);
	for(i=1;i<=4;i++)
		ListInsert_sq(&La,i,a[i-1]);
	InitList_sq(&Lb);	
	for(i=1;i<=7;i++)
		ListInsert_sq(&Lb,i,b[i-1]);
	
	printf("La= ");
	ListTraverse_sq(La,PrintElem);
	printf("\n");
	printf("Lb=");
	ListTraverse_sq(Lb,PrintElem);
	printf("\n\n");
	
	MergeSqlist_1(La,Lb,&Lc1);
	printf("合并La和Lb为Lc1=");
	ListTraverse_sq(Lc1,PrintElem);
	printf("\n\n");

	MergeSqlist_2(La,Lb,&Lc2);
	printf("合并La和Lb为Lc2=");
	ListTraverse_sq(Lc2,PrintElem);
	printf("\n\n");	

	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}
