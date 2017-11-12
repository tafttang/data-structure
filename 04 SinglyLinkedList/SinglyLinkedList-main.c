#include <stdio.h>
#include "SinglyLinkedList.c"
#define PressEnter
/*����ԭ��*/
int CmpGreater(LElemtype_L e,LElemtype_L data);		//�ж�data�Ƿ����e����data����e������TRUE 
void PrintElem(LElemtype_L e);						//���Ժ�������ӡ����

int main(int argc,char **argv)
{
	Linklist L;
	int i;
	LElemtype_L e;
	
	printf("���� InitList_L ����...\n");
	{
		printf("��ʼ��������L...\n");
		InitList_L(&L);
		printf("\n");
	}
	PressEnter;
	
	printf("���� LisrEmpty_L ����...\n");
	{
		ListEmpty_L(L) ? printf("L is empty!\n") : printf("L is not empty!\n");
		printf("\n");
	}
	PressEnter;
	
	printf("���� LisrInsert_L ����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("��L�ڣ�d��λ�ò���\"%d\"...\n",i,2*i);
			ListInsert_L(L,i,2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("���� ListTraverse_L ����...\n");
	{
		printf("L�е�Ԫ��Ϊ��L=");
		ListTraverse_L(L,PrintElem);
		printf("\n\n");		  
	}
	PressEnter;
	
	printf("���� ListLenghth_L ����...\n");
	{
		printf("L�ĳ���Ϊ%d\n",ListLength_L(L));
		printf("\n");
	}
	PressEnter;
	
	printf("���� ListDelete_L ����...\n");
	{
		printf("ɾ��L�еĵ�6��Ԫ��\"%d\"...\n",e);
		printf("L�е�Ԫ��Ϊ��L=");
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("���� GetElem_L ����...\n");
	{
		GetElem_L(L,4,&e);
		printf("L�еĵ�4��λ�õ�Ԫ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("���� LocateElem_L ����...\n");
	{
		i=LocateElem_L(L,7,CmpGreater);
		printf("L�е�һ��Ԫ��ֵ����\"7\"��Ԫ�ص�λ��Ϊ%d\n",i);
		printf("\n");
	}
	PressEnter;
	
	printf("���� PriorElem_L ����...\n");
	{
		PriorElem_L(L,6,&e);
		printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("���� NextElem_L ����...\n");
	{
		NextElem_L(L,6,&e);
		printf("Ԫ��\"6\"�ĺ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("���� ClearList_L ����...\n");
	{
		printf("���Lǰ:");
		ListEmpty_L(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");
		ClearList_L(L);
		printf("���L��:");
		ListEmpty_L(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");
		printf("\n");
	}
	PressEnter;
	
	printf("���� DestroyList_L ����...\n");
	{
		printf("����Lǰ:");
		L ? printf("L���ڣ�\n") : printf("L�����ڣ�\n");
		DestroyList_L(&L);
		printf("����L��:");
		L ? printf("L���ڣ�\n") : printf("L�����ڣ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("���� CreateList_HL ����...\n");
	{
		FILE *fp;
		Linklist L;
		printf("ͷ�巨����������L=");
		fp=fopen("TestData_HL.txt","r");
		CreateList_HL(fp,&L,5);
		fclose(fp);
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("���� CreateList_TL ����...\n");
	{
		FILE *fp; 
		Linklist L;
		printf("β�巨����������L=");
		fp=fopen("TestData_TL.txt","r");
		CreateList_TL(fp,&L,5);
		fclose(fp);
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
} 

int CmpGreater(LElemtype_L e,LElemtype_L data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(LElemtype_L e)
{
	printf("%d",e);
}
