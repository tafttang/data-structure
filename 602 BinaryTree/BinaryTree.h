//
// Created by El Fenomeno on 2017/11/12.
//

#ifndef INC_602_BINARYTREE_BINARYTREE_H
#define INC_602_BINARYTREE_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../00 xulun/Status.h"
#include "../00 xulun/Scanf.c"

/*二叉树相关类型定义*/
typedef char TElemType;     //假设二叉树元素均为字符
typedef struct BiTNode
{
    TElemType data;         //结点元素
    struct BiTNode* lchild; //左孩子指针
    struct BiTNode* rchild; //右孩子指针
}BiTNode;//二叉树结点

typedef BiTNode* BiTree;//指向二叉树结点的指针

/*栈元素类型*/
typedef BiTree SElemType_Sq; //重定义栈元素类型
#include "../12 SequenceStack new/SequenceStack.c"

/* 存储当前结点信息*/
/* 在求二叉树的长度的时候使用*/

typedef struct{
    BiTree left; //当前结点的左指针
    BiTree right; //当前结点的右指针
    int n; //当前结点的次序
}Node;

/*01 构造*/
void InitBiTree(BiTree *T);

/*02 清空*/
void ClearBiTree(BiTree *T);

/*03 销毁*/
void DestroyBiTree(BiTree *T);

/*04 判空*/
int BiTreeEmpty(BiTree T);

/*05 先序构造*/
int CreateBiTree(FILE *fp,BiTree *T);

/*06 长度*/
int BiTreeLength(BiTree T);

/*07 深度层数*/
int BiTreeDepth(BiTree T);

/*10 为某结点赋值,p为结点指针*/
void Assign(BiTree p,TElemType value);

/*16-1 获取指向结点e的指针*/
BiTree LocationBiTree_1(BiTree T,TElemType e);

/*17 将树T0插入到树T中成为结点e的子树，LR为插入标记，T0只有左子树*/
int InsertBiTree(BiTree T,TElemType e,BiTree T0,int LR);

/*19 层序遍历二叉树*/
void LevelOrderTraverse(BiTree T,void(Visit)(TElemType));

/*20-1 先序遍历二叉树*/
void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType));

/*20-2 算法6.1：先序遍历二叉树*/
int PreOrderTraverse_2(BiTree T,int(Visit)(TElemType));

/*21-1 */
void InOrderTraverse_1(BiTree T,void(Visit)(TElemType));

/*21-2 */
int InOrderTraverse_2(BiTree T,int(Visit)(TElemType));

/*21-3 */
int InOrderTraverse_3(BiTree T,int(Visit)(TElemType));

/*22 */
void PostOrderTraverse(BiTree T,void(Visit)(TElemType));

/*23*/
void PrintTree(BiTree T);

#endif //INC_602_BINARYTREE_BINARYTREE_H
