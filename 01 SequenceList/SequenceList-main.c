#include<stdio.h>
#include "SequenceList.c"
#define PressEnter

/*测试调用的函数原型*/

int CmpGreater(LElemType_Sq e,LElemType_Sq data);							//若data>e,返回TRUE,否则返回FALSE 
void PrintElem(LElemType_Sq e);													//测试函数，打印整型

int main(int argc,char **argv)
{
	Sqlist L;
	int i;
	LElemType_Sq e;
	
	printf("1.函数 Initlist_sq测试...\n");
	{
		printf("初始化顺序表L...\n");
		InitList_sq(&L);
		printf("\n");		
	} 
	PressEnter;
	
	printf("4.函数 ListEmpty_sq测试...\n");
	{
		ListEmpty_sq(L) ? printf("L为空\n"):printf("L不为空\n");
		printf("\n"); 
	}
	PressEnter;
	
	printf("10.函数 listinsert_sq测试...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("作为示范，在L第%d个位置上插入\"%d\"...\n",i,2*i); 
			ListInsert_sq(&L,i,2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("12.函数ListTraverse_sq测试...\n");
	{
		printf("L中的元素为：L=");
		ListTraverse_sq(L,PrintElem);
		printf("\n\n"); 
	}
	PressEnter;
	
	printf("5.函数Listlength_sq测试...\n");
	{
		i=ListLength_sq(L);
		printf("L的长度为%d \n",i);
		printf("\n");
	} 
	PressEnter;
	
	printf("6.函数GetElem_sq测试...\n");
	{
		GetElem_sq(L,4,&e);
		printf("L中第四个位置的元素为\"%d\"\n",e);
		printf("\n");
	} 
	PressEnter;
	
	printf("7.函数 locateelem_sq测试...\n"); 
	{
		i=LocateElem_Sq(L,7,CmpGreater);
		printf("L中第一个元素值大于\"7\"的元素的位置为%d\n",i);
		printf("\n"); 
	} 
	PressEnter;

	printf("8.函数priorelem_sq测试...\n");
	{
		PriorElem_Sq(L,6,&e);
		printf("元素\"6\"的前驱为\"%d\"\n",e);
		printf("\n");
	} 
	PressEnter;
	
	printf("9.函数 Nextelem_sq测试...\n");
	{
		NextElem_Sq(L,6,&e);
		printf("元素\"6\"的后继为\"%d\"\n",e);
		printf("\n");
	} 
	PressEnter;

	printf("2.函数ClearList_sq测试...\n");
	{
		printf("清空L前: ");
		L.elem ? printf("L为空!\n") : printf("L不为空!\n") ;
		DestroyList_Sq(&L);
		printf("销毁L后:");
		L.elem ? printf("L存在!\n") : printf("L不存在!\n") ;
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

