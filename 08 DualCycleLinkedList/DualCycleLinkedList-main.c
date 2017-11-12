#include <stdio.h>
#include "DualCycleLinkedList.c"
#define PressEnter

int CmpGreater(LElemType_DC e,LElemType_DC data);
void PrintElem(LElemType_DC e);

int main(int argc,char **argv)
{
	DuLinklist L;
	LElemType_DC e;
	int i;
	
	printf("1����InitList_Dul����....\n");
	{
		printf("��ʼ��˫ѭ������L...\n");
		InitList_DuL(&L);
		printf("\n");
	}
	PressEnter;
	
	printf("7ListEmpty_DuL....\n");
	{
		ListEmpty_DuL(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n"); 
		printf("\n");
	}
	PressEnter;
	
	printf("13���뺯��....\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("��L��%d��λ���ϲ���\"%d\"...\n",i,2*i);
			ListInsert_Dul(L,i,2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("15....\n");
	{
		printf("L�е�Ԫ��Ϊ��L= ");
		ListTraverse_DuL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("8....\n");
	{
		printf("L�ĳ���Ϊ%d \n",ListLength_DuL(L));
		printf("\n");
	}
	PressEnter;
	
	printf("14....\n");
	{
		ListDelete_DuL(L,6,&e);
		printf("ɾ��L�еĵ�6��Ԫ��\"%d\"...\n",e);
		printf("L�е�Ԫ��Ϊ��H= ");
		ListTraverse_DuL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("9....\n");
	{
		GetElem_DuL(L,4,&e);
		printf("L�еĵ�4��λ�õ�Ԫ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("10....\n");
	{
		i = LocateElem_DuL(L,7,CmpGreater);
		printf("L�е�һ��Ԫ��ֵ����\"7\"��Ԫ�ص�λ��Ϊ%d \n",i);
		printf("\n");
	}
	PressEnter;
	
	printf("11....\n");
	{
		PriorElem_DuL(L,6,&e);
		printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("12....\n");
	{
		NextElem_DuL(L,6,&e);
		printf("Ԫ��\"6\"�ĺ��Ϊ\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("����GetElem_P����...\n");
	{
		DuLinklist p;
		p = GetElemPtr_DuL(L,3);
		printf("�����3������ָ��Ϊ0x%x�����Ӧ��ֵΪ\"%d\"\n",p,*p);
		printf("\n");
	}
	PressEnter;
	
	printf("5....\n");
	{
		printf("���Lǰ: ");
		ListEmpty_DuL(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");
		ClearList_DuL(L);
		printf("���L��: ");
		ListEmpty_DuL(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");
		printf("\n");
	}
	PressEnter;
	
	printf("6....\n");
	{
		printf("����Lǰ: ");
		L ? printf("L���ڣ���\n") : printf("L�����ڣ���\n");
		DestroyList_DuL(&L);
		printf("����H��: ");
		L ? printf("L���ڣ���\n") : printf("L�����ڣ���\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

int CmpGreater(LElemType_DC e,LElemType_DC data)
{
	return data>e ? TRUE : FALSE; 
}

void PrintElem(LElemType_DC e)
{
	printf("%d",e);
}
