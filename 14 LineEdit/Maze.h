#ifndef	MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../00 Status/Status.h"

/*�궨��*/
#define N 15
#define X 4

#define SleepTime 2

/*�Թ����Ͷ���*/
typedef enum
{
	Wall,
	Obstacle,
	Way,
	DeadLock,
	East,South,West,North
}MazeNode;

typedef struct
{
	int x;
	int y;
}PosType;
typedef struct
{
	int ord;
	PosType seat;
	int di;
}SElemType_Sq;

#include "../12 SequenceStack/SequenceStack.c"
typedef int MazeType;

/*�Թ������б�*/
//01.�㷨3.3 �Թ�Ѱ·����ٷ��� 
int MazePath(MazeType maze[][N],PostType start,PosType end); 

//02.�Թ��ĳ�ʼ������������ڵĳ�ʼ��
void InitMaze(MazeType maze[][N],PosType *start,PosType *end);
