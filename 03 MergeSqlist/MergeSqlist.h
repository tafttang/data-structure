#ifndef MERGELIST_H
#define MERGELIST_H

#include<stdlib.h>
#include "../01 SequenceList/SequenceList.c"

//顺序表归并函数列表
void Mergelist_1(Sqlist La,Sqlist Lb,Sqlist *Lc);
//2.2：求C=A+B，A,B,C均为非递减序列

void Mergelist_2(Sqlist La,Sqlist Lb,Sqlist *Lc);
//2.7:求C=A+B，A,B,C均为非递减序列

#endif

