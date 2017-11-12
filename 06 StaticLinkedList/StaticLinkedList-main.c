#include <stdio.h>
#include "StaticLinkedList.c"
#define PressEnter

void PrintElem(LElemType_S e);		//���Ժ�������ӡ����

int main(int argc,char **argv)
{
	SLinkList H;
	LElemType_S e;
	int i;
	
	printf("1����InitSpace_SL����....\n");
	{
		printf("��ʼ����̬����ı��ÿռ�SPACE...\n");
		InitSpace_SL();
		printf("\n");
	}
	PressEnter;
	
	printf("2����Malloc_SL��InitList_SL����....\n");
	{
		printf("��ʼ����̬����H����Malloc_SL����ռ�...\n");
		InitList_SL(&H);
		printf("\n");
	}
	PressEnter;
	
	printf("7....\n");
	{
		printf("...\n");
		ListEmpty_SL(H) ? printf("HΪ�գ���\n") : printf("H��Ϊ�գ���\n"); 
		printf("\n");
	}
	PressEnter;
	
	printf("13....\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("��H��%d��λ���ϲ���\"%d\"...\n",i,2*i);
			ListInsert_SL(H,i,2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("15....\n");
	{
		printf("H�е�Ԫ��Ϊ��H= ");
		ListTraverse_SL(H,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("8....\n");
	{
		printf("H�ĳ���Ϊ%d \n",ListLength_SL(H));
		printf("\n");
	}
	PressEnter;
	
	printf("14....\n");
	{
		ListDelete_SL(H,6,&e);
		printf("ɾ��H�еĵ�6��Ԫ��\"%d\"����Free_SL()�ͷſռ�...\n",e);
		printf("H�е�Ԫ��Ϊ��H= ");
		ListTraverse_SL(H,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("9....\n");
	{
		GetElem_SL(H,4,&e);
		printf("H�еĵ�4��λ�õ�Ԫ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("10....\n");
	{
		GetElem_SL(H,4,&e);
		printf("Ԫ��\"8\"��H�е�λ��Ϊ%d \n",LocateElem_SL(H,8));
		printf("\n");
	}
	PressEnter;
	
	printf("11....\n");
	{
		PriorElem_SL(H,6,&e);
		printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("12....\n");
	{
		NextElem_SL(H,6,&e);
		printf("Ԫ��\"6\"�ĺ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("5....\n");
	{
		printf("���Hǰ: ");
		ListEmpty_SL(H) ? printf("HΪ�գ���\n") : printf("H��Ϊ�գ���\n");
		ClearList_SL(H);
		printf("���H��: ");
		ListEmpty_SL(H) ? printf("HΪ�գ���\n") : printf("H��Ϊ�գ���\n");
		printf("\n");
	}
	PressEnter;
	
	printf("6....\n");
	{
		printf("����Hǰ: ");
		H ? printf("H���ڣ���\n") : printf("H�����ڣ���\n");
		DestroyList_SL(&H);
		printf("����H��: ");
		H ? printf("H���ڣ���\n") : printf("H�����ڣ���\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
} 

void PrintElem(LElemType_S e)
{
	printf("%d",e);
}
