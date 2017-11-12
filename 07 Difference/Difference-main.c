#include <stdio.h>
#include "Difference.c"

void PrintElem(LElemType_S e); 

int main(int argc,char **argv)
{
	SLinkList S;
	FILE *fp;
	int len_A,len_B,i;
	LElemType_S A[100],B[100];
	
	len_A = 3;
	len_B = 5;
	
	fp = fopen("TestData.txt","r");		//�ļ�ָ�룬ָ������Դ 
	for(i=0;i<len_A;i++)				//����A 
		Scanf(fp,"%d",&A[i]);
	for(i=0;i<len_B;i++)				//����B 
		Scanf(fp,"%d",&B[i]);
	fclose(fp);
	
	printf("A= ");
	for(i=0;i<len_A;i++)
		PrintElem(A[i]);
	printf("\n");
	printf("B = ");
	for(i=0;i<len_B;i++)
		PrintElem(B[i]);
	printf("\n\n");
	
	printf("S = (A-B)��(B-A)= "); 
	difference(&S,A,len_A,B,len_B);
	ListTraverse_SL(S,PrintElem);
	printf("\n\n");
	
	return 0;
}

void PrintElem(LElemType_S e)
{
	printf("%d",e);
}
