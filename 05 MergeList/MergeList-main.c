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
	
	printf("��Ϊʾ����La�����趨Ϊ%d��Lb�����趨Ϊ%d������La��Lb..\n",m,m);
	fp=fopen("TESTData_HL.txt","r");		//�ļ�ָ�룬ָ������Դ 
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
	printf("�ϲ�La��LbΪLc = ");
	ListTraverse_L(Lc,PrintElem);
	printf("\n\n");
	PressEnter;
	
	return 0;
}

void PrintElem(LElemtype_L e)
{
	printf("%d",e);
}
