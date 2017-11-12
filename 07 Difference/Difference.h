#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <stdio.h>
#include "../00 xulun/Scanf.c"

#include "../06 StaticLinkedList/StaticLinkedList.c"

//算法2.1：在一维数组中建立集合(A-B)∪(B-A) 
void difference(SLinkList *S,LElemType_S A[],int len_A,LElemType_S B[],int len_B);

#endif
