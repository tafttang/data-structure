//
// Created by El Fenomeno on 2017/10/30.
//

#ifndef INC_17_LINKQUEUE_LINKQUEUE_H
#define INC_17_LINKQUEUE_LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../00 xulun/Status.h"

typedef int QElemType_L;
typedef struct {
    QElemType_L data;
    struct QNode *next;
}QNode;

typedef QNode* QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

int InitQueue_L(LinkQueue *Q);

void ClearQueue_L(LinkQueue *Q);

void DestroyQueue_L(LinkQueue *Q);

int QueueEmpty_L(LinkQueue *Q);

int QueueLength_L(LinkQueue Q);

int GetHead_L(LinkQueue Q,QElemType_L *e);

int EnQueue_L(LinkQueue *Q,QElemType_L e);

int Dequeue_L(LinkQueue Q,void(Visit)(QElemType_L));


#endif //INC_17_LINKQUEUE_LINKQUEUE_H
