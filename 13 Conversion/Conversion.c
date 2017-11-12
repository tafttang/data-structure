#ifndef CONVERSION_C
#define CONVERSION_C

#include "conversion.h"

void conversion(int i)
{
	SqStack S;
	SElemType_Sq e;
	
	InitStack_Sq(&S);
	
	printf("ʮ������%d ת��Ϊ�˽�������Ϊ��0",i);
	
	while(i)
	{//��ջʱ�ӵ�λ����λ 
		Push_Sq(&S,i%8);
		i = i/8;
	} 
	
	while(!StackEmpty_Sq(S))
	{//��ջʱ�Ӹ�λ����λ 
		Pop_Sq(&S,&e);
		printf("%d",e);
	}
}

#endif
