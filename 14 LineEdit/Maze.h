#ifndef	MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../00 Status/Status.h"

/*宏定义*/
#define N 15
#define X 4

#define SleepTime 2

/*迷宫类型定义*/
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

/*迷宫函数列表*/
//01.算法3.3 迷宫寻路（穷举法） 
int MazePath(MazeType maze[][N],PostType start,PosType end); 

//02.迷宫的初始化，包括出入口的初始化
void InitMaze(MazeType maze[][N],PosType *start,PosType *end);
