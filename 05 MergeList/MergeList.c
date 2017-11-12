#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeList.h"

void MergeList_L(Linklist La,Linklist *Lb,Linklist *Lc)
{//ָ��Lb,LcҪ�ı䣬���β���ָ��ָ���ָ�� 
	Linklist pa,pb,pc;
	
	pa=La->next;
	pb=(*Lb)->next;
	pc=*Lc=La;						//��La��ͷ�����ΪLc��ͷ��� 
	
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next = pa ? pa : pb;	//��pa�ǿ�ָ��Ͱ�pa�ĸ�ֵ��pc->next����Ȼ�Ͱ�pb��ֵ����pc->next 
	
	free(*Lb);					//�ͷ�Lb��ͷ���
	*Lb=NULL; 
}

#endif
