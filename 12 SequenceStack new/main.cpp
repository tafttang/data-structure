#include <stdio.h>
#include "Sequencestack.C"
#define PressEnter


void PrintElem(SElemType_Sq e);

int main(int argc,char **argv)
{
    SqStack S;
    int i;
    SElemType_Sq e;

    printf("1.ceshi InitStack...\n");
    {
        printf("chushihua S ...\n");
        InitStack_Sq(&S);
        printf("\n");
    }
    PressEnter;

    printf("4 ceshi stackempty...\n");
    {
        StackEmpty_Sq(S) ? printf("S wei kong \n") : printf("S buweikong \n");
        printf("\n");
    }
    PressEnter;

    printf("7 ceshi Push....\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("jiang \"%2d\" yaru zhan S",2*i);
            Push_Sq(&S,2*i);
            printf("(leiji di%dge yuansu)...\n",S.top-S.base);
        }
        printf("\n");
    }
    PressEnter;

    printf("9.ceshi StackTraverse ....\n");
    {
        printf("S zhong de yuansu wei S = ");
        StackTraverse_Sq(S,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("8 ceshi Pop...\n");
    {
        Pop_Sq(&S,&e);
        printf("zhanding yuansu \"%d\" chuzhan...\n",e);
        printf("S zhong de yuansu wei : S = ");
        StackTraverse_Sq(S,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("5 hanshu StackLength  ceshi....\n");
    {
        i = StackLength_Sq(S);
        printf("S de changdu wei %d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("6 hanshu Gettop ceshi ....\n");
    {
        GetTop_Sq(S,&e);
        printf("zhanding yuansu de zhi wei \"%d\"\n",e);
        printf("\n");
    }
    PressEnter;

    printf("3 ceshi Clearstack....\n");
    {
        printf("qingkong S qian");
        StackEmpty_Sq(S) ? printf("S weikong!! \n") : printf("S buweikong !!\n");
        ClearStack_Sq(&S);
        printf("qingkong S hou");
        StackEmpty_Sq(S) ? printf("Sweikong !!\n") : printf("Sbuweikong !!\n");
        printf("\n");
    }
    PressEnter;

    printf("2 hanshu DestroyStack ceshi...\n");
    {
        printf("xiaohui S qian");
        S.base!=NULL && S.top!=NULL ? printf("S cunzai !! \n") : printf("S bucunzai !!\n");
        DestroyStack_Sq(&S);
        printf("xiaohui S hou");
        S.base!=NULL && S.top!=NULL ? printf("S cunzai !!\n") : printf("S bucunzai !!\n");
    }
    PressEnter;

    return 0;
}

void PrintElem(SElemType_Sq e)
{
    printf("%d",e);
}