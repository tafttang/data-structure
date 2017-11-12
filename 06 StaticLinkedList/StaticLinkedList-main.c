#include <stdio.h>
#include "StaticLinkedList.c"
#define PressEnter

void PrintElem(LElemType_S e);		//测试函数，打印整型

int main(int argc,char **argv)
{
	SLinkList H;
	LElemType_S e;
	int i;
	
	printf("1函数InitSpace_SL测试....\n");
	{
		printf("初始化静态链表的备用空间SPACE...\n");
		InitSpace_SL();
		printf("\n");
	}
	PressEnter;
	
	printf("2函数Malloc_SL、InitList_SL测试....\n");
	{
		printf("初始化静态链表H，用Malloc_SL申请空间...\n");
		InitList_SL(&H);
		printf("\n");
	}
	PressEnter;
	
	printf("7....\n");
	{
		printf("...\n");
		ListEmpty_SL(H) ? printf("H为空！！\n") : printf("H不为空！！\n"); 
		printf("\n");
	}
	PressEnter;
	
	printf("13....\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在H第%d个位置上插入\"%d\"...\n",i,2*i);
			ListInsert_SL(H,i,2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("15....\n");
	{
		printf("H中的元素为：H= ");
		ListTraverse_SL(H,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("8....\n");
	{
		printf("H的长度为%d \n",ListLength_SL(H));
		printf("\n");
	}
	PressEnter;
	
	printf("14....\n");
	{
		ListDelete_SL(H,6,&e);
		printf("删除H中的第6个元素\"%d\"，用Free_SL()释放空间...\n",e);
		printf("H中的元素为：H= ");
		ListTraverse_SL(H,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("9....\n");
	{
		GetElem_SL(H,4,&e);
		printf("H中的第4个位置的元素为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("10....\n");
	{
		GetElem_SL(H,4,&e);
		printf("元素\"8\"在H中的位序为%d \n",LocateElem_SL(H,8));
		printf("\n");
	}
	PressEnter;
	
	printf("11....\n");
	{
		PriorElem_SL(H,6,&e);
		printf("元素\"6\"的前驱为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("12....\n");
	{
		NextElem_SL(H,6,&e);
		printf("元素\"6\"的后继为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("5....\n");
	{
		printf("清空H前: ");
		ListEmpty_SL(H) ? printf("H为空！！\n") : printf("H不为空！！\n");
		ClearList_SL(H);
		printf("清空H后: ");
		ListEmpty_SL(H) ? printf("H为空！！\n") : printf("H不为空！！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("6....\n");
	{
		printf("销毁H前: ");
		H ? printf("H存在！！\n") : printf("H不存在！！\n");
		DestroyList_SL(&H);
		printf("销毁H后: ");
		H ? printf("H存在！！\n") : printf("H不存在！！\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
} 

void PrintElem(LElemType_S e)
{
	printf("%d",e);
}
