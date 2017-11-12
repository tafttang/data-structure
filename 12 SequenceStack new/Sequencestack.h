//
// Created by El Fenomeno on 2017/11/12.
//

#ifndef INC_12_SEQUENCESTACK_NEW_SEQUENCESTACK_H
#define INC_12_SEQUENCESTACK_NEW_SEQUENCESTACK_H


#include <stdio.h>
#include <stdlib.h>
#include "../00 xulun/Status.h"


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char SElemType_Sq;

typedef struct
{
    SElemType_Sq *base;
    SElemType_Sq *top;
    int stacksize;
}SqStack;


int InitStack_Sq(SqStack *S);


int DestroyStack_Sq(SqStack *S);


int ClearStack_Sq(SqStack *S);


int StackEmpty_Sq(SqStack S);


int StackLength_Sq(SqStack S);


int GetTop_Sq(SqStack S,SElemType_Sq *e);


int Push_Sq(SqStack *S,SElemType_Sq e);


int Pop_Sq(SqStack *S,SElemType_Sq *e);


int StackTraverse_Sq(SqStack S,void(Visit)(SElemType_Sq));



#endif //INC_12_SEQUENCESTACK_NEW_SEQUENCESTACK_H
