#ifndef LINEEDIT_C
#define LINEEDIT_C

#include "LineEdit.h"

/*与严蔚敏课本所述算法略有差别，但算法思想一致*/
void LineEdit(char Buffer[])
{
	SqStack S;
	SElemType_Sq e;
	int i;
	char ch;
	
	InitStack_Sq(&S);
	
	i = 0;
	ch = Buffer[i++];
	while(ch!='\0')//ch不是字符串的结束符 
	{
		while(ch!='\0' && ch!='\n')
		{//ch不是字符串的结束符也不是换行符 
			switch(ch)
			{
				case '#':Pop_Sq(&S,&e);
					break;
				case '@':ClearStack_Sq(&S);
					break;
				default :Push_Sq(&S,ch);
			}
			ch = Buffer[i++];//从终端接收下一个字符 
		}
		
		if(ch=='\n')//如果等于换行符 
		{
			Push_Sq(&S,ch);
			StackTraverse_Sq(S,Print);
			ClearStack_Sq(&S);
			ch = Buffer[i++];
		}
	}
	
	if(ch == '\0')//如果等于换行符 
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
