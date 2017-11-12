#include<stdio.h>
#include "SequenceList.c"
#define PressEnter

/*���Ե��õĺ���ԭ��*/

int CmpGreater(LElemType_Sq e,LElemType_Sq data);							//��data>e,����TRUE,���򷵻�FALSE 
void PrintElem(LElemType_Sq e);													//���Ժ�������ӡ����

int main(int argc,char **argv)
{
	Sqlist L;
	int i;
	LElemType_Sq e;
	
	printf("1.���� Initlist_sq����...\n");
	{
		printf("��ʼ��˳���L...\n");
		InitList_sq(&L);
		printf("\n");		
	} 
	PressEnter;
	
	printf("4.���� ListEmpty_sq����...\n");
	{
		ListEmpty_sq(L) ? printf("LΪ��\n"):printf("L��Ϊ��\n");
		printf("\n"); 
	}
	PressEnter;
	
	printf("10.���� listinsert_sq����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("��Ϊʾ������L��%d��λ���ϲ���\"%d\"...\n",i,2*i); 
			ListInsert_sq(&L,i,2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("12.����ListTraverse_sq����...\n");
	{
		printf("L�е�Ԫ��Ϊ��L=");
		ListTraverse_sq(L,PrintElem);
		printf("\n\n"); 
	}
	PressEnter;
	
	printf("5.����Listlength_sq����...\n");
	{
		i=ListLength_sq(L);
		printf("L�ĳ���Ϊ%d \n",i);
		printf("\n");
	} 
	PressEnter;
	
	printf("6.����GetElem_sq����...\n");
	{
		GetElem_sq(L,4,&e);
		printf("L�е��ĸ�λ�õ�Ԫ��Ϊ\"%d\"\n",e);
		printf("\n");
	} 
	PressEnter;
	
	printf("7.���� locateelem_sq����...\n"); 
	{
		i=LocateElem_Sq(L,7,CmpGreater);
		printf("L�е�һ��Ԫ��ֵ����\"7\"��Ԫ�ص�λ��Ϊ%d\n",i);
		printf("\n"); 
	} 
	PressEnter;

	printf("8.����priorelem_sq����...\n");
	{
		PriorElem_Sq(L,6,&e);
		printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\"\n",e);
		printf("\n");
	} 
	PressEnter;
	
	printf("9.���� Nextelem_sq����...\n");
	{
		NextElem_Sq(L,6,&e);
		printf("Ԫ��\"6\"�ĺ��Ϊ\"%d\"\n",e);
		printf("\n");
	} 
	PressEnter;

	printf("2.����ClearList_sq����...\n");
	{
		printf("���Lǰ: ");
		L.elem ? printf("LΪ��!\n") : printf("L��Ϊ��!\n") ;
		DestroyList_Sq(&L);
		printf("����L��:");
		L.elem ? printf("L����!\n") : printf("L������!\n") ;
	 	printf("\n");
	}
 	PressEnter;
 	
 	return 0;
} 

int CmpGreater(LElemType_Sq e,LElemType_Sq data)
{
	return data>e ? TRUE : FALSE;	
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}

