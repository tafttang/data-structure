//
// Created by El Fenomeno on 2017/11/12.
//
#include "BinaryTree.h"
void InitBiTree(BiTree *T)
{
    *T = NULL;
}

int BiTreeEmpty(BiTree T)
{
    return T=NULL ? TRUE : ERROR ;
}

int CreateBiTree(FILE *fp,BiTree *T)
{
    char ch;

    Scanf(fp,"%c",&ch);

    if(ch == ' ^')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!(*T))
            exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(fp,&(*T)->lchild);
        CreateBiTree(fp,&(*T)->rchild);
    }

    return OK;
}


int BiTreeLength(BiTree T)
{
    Node node[100];
    int i,len;

    i = len =0;
    if(T)
    {
        node[i].left=T->lchild;
        node[i].right=T->rchild;
        node[i].n = 1;
        if(node[i].n>len)
            len = node[i].n;

        while (i)
    }
}


int BiTreeDepth(BiTree T)
{
    int LD,RD;

    if(T=NULL)
        return 0;//空树深度为0

    else
    {
        LD = BiTreeDepth(T->lchild);//求左子树深度
        RD = BiTreeDepth(T->rchild);//求右子树深度

        return (LD>=RD?LD:RD)+1;
    }
}


void PrintTree(BiTree T)
{
    int row,col;
    int i,j,m,l,r;
    BiTNode a[100][100] = {};

    if(T)
    {
        row = BiTreeDepth(T);
        col = pow(2,row) - 1;

        for(i=1; i<= row-1;i++)
        {
            for(j=1;j<=pow(2,i-1);j++)
            {
                m = (2*j-1)*pow(2,row-i);
                l = (4*j-3)*pow(2,row-i-1);
                r = (4*j-1)*pow(2,row-i-1);

                if(i==1)
                    a[i][m] = *T;

                if(a[i][m].lchild)
                    a[i+1][1] = *(a[i][m].lchild);
                if(a[i][m].rchild)
                    a[i+1][r] = *(a[i][m].rchild);
            }
        }

        for(i=1; i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
                if(a[i][j].data)
                    printf("%c",a[i][j].data);
                else
                    printf("\n");
            }
            printf("\n");
        }
    }

}

