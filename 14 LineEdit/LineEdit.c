#ifndef LINEEDIT_C
#define LINEEDIT_C

#include "LineEdit.h"

/*����ε���α������㷨���в�𣬵��㷨˼��һ��*/
void LineEdit(char Buffer[])
{
	SqStack S;
	SElemType_Sq e;
	int i;
	char ch;
	
	InitStack_Sq(&S);
	
	i = 0;
	ch = Buffer[i++];
	while(ch!='\0')//ch�����ַ����Ľ����� 
	{
		while(ch!='\0' && ch!='\n')
		{//ch�����ַ����Ľ�����Ҳ���ǻ��з� 
			switch(ch)
			{
				case '#':Pop_Sq(&S,&e);
					break;
				case '@':ClearStack_Sq(&S);
					break;
				default :Push_Sq(&S,ch);
			}
			ch = Buffer[i++];//���ն˽�����һ���ַ� 
		}
		
		if(ch=='\n')//������ڻ��з� 
		{
			Push_Sq(&S,ch);
			StackTraverse_Sq(S,Print);
			ClearStack_Sq(&S);
			ch = Buffer[i++];
		}
	}
	
	if(ch == '\0')//������ڻ��з� 
	{
		StackTraverse_Sq(S,Print);
		DestroyStack_Sq(&S);
	}
}

void Print(SElemType_Sq e)
{
	printf("%c",e);
}

#endif
