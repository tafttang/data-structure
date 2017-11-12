//
// Created by El Fenomeno on 2017/10/30.

#ifndef LINKQUEUE_C
#define LINKQUEUE_C

#include "LinkQueue.h"

int InitQueue_L(LinkQueue *Q)
{
    (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next = NULL;
    return  OK;
}

void ClearQueue_L(LinkQueue *Q)
{
    (*Q).front = (*Q).rear
}