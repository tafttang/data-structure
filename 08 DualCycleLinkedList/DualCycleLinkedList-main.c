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
	
	printf("1函数InitList_Dul测试....\n");
	{
		printf("初始化双循环链表L...\n");
		InitList_DuL(&L);
		printf("\n");
	}
	PressEnter;
	
	printf("7ListEmpty_DuL....\n");
	{
		ListEmpty_DuL(L) ? printf("L为空！！\n") : printf("L不为空！！\n"); 
		printf("\n");
	}
	PressEnter;
	
	printf("13插入函数....\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在L第%d个位置上插入\"%d\"...\n",i,2*i);
			ListInsert_Dul(L,i,2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("15....\n");
	{
		printf("L中的元素为：L= ");
		ListTraverse_DuL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("8....\n");
	{
		printf("L的长度为%d \n",ListLength_DuL(L));
		printf("\n");
	}
	PressEnter;
	
	printf("14....\n");
	{
		ListDelete_DuL(L,6,&e);
		printf("删除L中的第6个元素\"%d\"...\n",e);
		printf("L中的元素为：H= ");
		ListTraverse_DuL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("9....\n");
	{
		GetElem_DuL(L,4,&e);
		printf("L中的第4个位置的元素为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("10....\n");
	{
		i = LocateElem_DuL(L,7,CmpGreater);
		printf("L中第一个元素值大于\"7\"的元素的位置为%d \n",i);
		printf("\n");
	}
	PressEnter;
	
	printf("11....\n");
	{
		PriorElem_DuL(L,6,&e);
		printf("元素\"6\"的前驱为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("12....\n");
	{
		NextElem_DuL(L,6,&e);
		printf("元素\"6\"的后继为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("函数GetElem_P测试...\n");
	{
		DuLinklist p;
		p = GetElemPtr_DuL(L,3);
		printf("链表第3个结点的指针为0x%x，其对应的值为\"%d\"\n",p,*p);
		printf("\n");
	}
	PressEnter;
	
	printf("5....\n");
	{
		printf("清空L前: ");
		ListEmpty_DuL(L) ? printf("L为空！！\n") : printf("L不为空！！\n");
		ClearList_DuL(L);
		printf("清空L后: ");
		ListEmpty_DuL(L) ? printf("L为空！！\n") : printf("L不为空！！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("6....\n");
	{
		printf("销毁L前: ");
		L ? printf("L存在！！\n") : printf("L不存在！！\n");
		DestroyList_DuL(&L);
		printf("销毁H后: ");
		L ? printf("L存在！！\n") : printf("L不存在！！\n");
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
