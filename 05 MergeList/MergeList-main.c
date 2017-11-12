#include <stdio.h>
#include "MergeList.c"
#define PressEnter 

void PrintElem(LElemtype_L e);

int main(int argc,char **argv)
{
	FILE *fp;
	Linklist La,Lb,Lc;
	int m;
	
	m=5;
	
	printf("作为示例，La长度设定为%d，Lb长度设定为%d，创建La和Lb..\n",m,m);
	fp=fopen("TESTData_HL.txt","r");		//文件指针，指向数据源 
	CreateList_HL(fp,&La,m);
	fclose(fp);
	fp=fopen("TESTData_TL.txt","r");	
	CreateList_TL(fp,&Lb,m);
	fclose(fp); 
	
	printf("La= ");
	ListTraverse_L(La,PrintElem);
	printf("\n");
	printf("Lb=");
	ListTraverse_L(Lb,PrintElem);
	printf("\n\n");
	PressEnter;
	
	MergeList_L(La,&Lb,&Lc);
	printf("合并La和Lb为Lc = ");
	ListTraverse_L(Lc,PrintElem);
	printf("\n\n");
	PressEnter;
	
	return 0;
}

void PrintElem(LElemtype_L e)
{
	printf("%d",e);
}
