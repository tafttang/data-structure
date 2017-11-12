#ifndef CONVERSION_C
#define CONVERSION_C

#include "conversion.h"

void conversion(int i)
{
	SqStack S;
	SElemType_Sq e;
	
	InitStack_Sq(&S);
	
	printf("十进制数%d 转换为八进制数后为：0",i);
	
	while(i)
	{//进栈时从低位到高位 
		Push_Sq(&S,i%8);
		i = i/8;
	} 
	
	while(!StackEmpty_Sq(S))
	{//出栈时从高位到低位 
		Pop_Sq(&S,&e);
		printf("%d",e);
	}
}

#endif
