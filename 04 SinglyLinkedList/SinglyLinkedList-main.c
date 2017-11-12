#include <stdio.h>
#include "SinglyLinkedList.c"
#define PressEnter
/*函数原型*/
int CmpGreater(LElemtype_L e,LElemtype_L data);		//判断data是否大于e，若data大于e，返回TRUE 
void PrintElem(LElemtype_L e);						//测试函数，打印整型

int main(int argc,char **argv)
{
	Linklist L;
	int i;
	LElemtype_L e;
	
	printf("函数 InitList_L 测试...\n");
	{
		printf("初始化单链表L...\n");
		InitList_L(&L);
		printf("\n");
	}
	PressEnter;
	
	printf("函数 LisrEmpty_L 测试...\n");
	{
		ListEmpty_L(L) ? printf("L is empty!\n") : printf("L is not empty!\n");
		printf("\n");
	}
	PressEnter;
	
	printf("函数 LisrInsert_L 测试...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在L第％d个位置插入\"%d\"...\n",i,2*i);
			ListInsert_L(L,i,2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("函数 ListTraverse_L 测试...\n");
	{
		printf("L中的元素为；L=");
		ListTraverse_L(L,PrintElem);
		printf("\n\n");		  
	}
	PressEnter;
	
	printf("函数 ListLenghth_L 测试...\n");
	{
		printf("L的长度为%d\n",ListLength_L(L));
		printf("\n");
	}
	PressEnter;
	
	printf("函数 ListDelete_L 测试...\n");
	{
		printf("删除L中的第6个元素\"%d\"...\n",e);
		printf("L中的元素为：L=");
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("函数 GetElem_L 测试...\n");
	{
		GetElem_L(L,4,&e);
		printf("L中的第4个位置的元素为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("函数 LocateElem_L 测试...\n");
	{
		i=LocateElem_L(L,7,CmpGreater);
		printf("L中第一个元素值大于\"7\"的元素的位置为%d\n",i);
		printf("\n");
	}
	PressEnter;
	
	printf("函数 PriorElem_L 测试...\n");
	{
		PriorElem_L(L,6,&e);
		printf("元素\"6\"的前驱为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("函数 NextElem_L 测试...\n");
	{
		NextElem_L(L,6,&e);
		printf("元素\"6\"的后继为\"%d\"\n",e);
		printf("\n");
	}
	PressEnter;
	
	printf("函数 ClearList_L 测试...\n");
	{
		printf("清空L前:");
		ListEmpty_L(L) ? printf("L为空！！\n") : printf("L不为空！！\n");
		ClearList_L(L);
		printf("清空L后:");
		ListEmpty_L(L) ? printf("L为空！！\n") : printf("L不为空！！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("函数 DestroyList_L 测试...\n");
	{
		printf("销毁L前:");
		L ? printf("L存在！\n") : printf("L不存在！\n");
		DestroyList_L(&L);
		printf("销毁L后:");
		L ? printf("L存在！\n") : printf("L不存在！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("函数 CreateList_HL 测试...\n");
	{
		FILE *fp;
		Linklist L;
		printf("头插法建立单链表L=");
		fp=fopen("TestData_HL.txt","r");
		CreateList_HL(fp,&L,5);
		fclose(fp);
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("函数 CreateList_TL 测试...\n");
	{
		FILE *fp; 
		Linklist L;
		printf("尾插法建立单链表L=");
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
