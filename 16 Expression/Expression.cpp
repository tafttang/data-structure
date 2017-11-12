//
// Created by El Fenomeno on 2017/10/25.

#ifndef EXPRESSION_C
#define EXPRESSION_C

#include "Expression.h"

//01 3.4表达式求值，假设表达式中操作数均只有一位
OperandType EvaluateExpression(char exp[])
{//从exp读入表达式
    SqStack OPTR,OPND;//符号栈和数字栈
    SElemType_Sq e,ch;
    OperatorType theta,x;//符号
    OperandType a,b;//数字
    int i;

    InitStack_Sq(&OPTR);
    Push_Sq(&OPTR,'#');
    InitStack_Sq(&OPND);

    i = 0;
    ch = exp[i++];
    while(ch!='#'||GetTop_OPTR(OPTR)!='#')
    {
        if(!In(ch))
        {//c不是符号则入栈
            Push_Sq(&OPND,ch);
            ch = exp[i++];
        }
        else
        {
            switch(Precede(GetTop_OPTR(OPTR),ch))
            {
                case '<'://栈中符号优先级低，继续进栈
                    Push_Sq(&OPTR,ch);
                    ch = exp[i++];
                    break;

                case '='://优先级相等时，说明遇到括号，需要脱括号
                    Pop_Sq(&OPTR,&x);
                    ch = exp[i++];
                    break;
                case '>'://栈中操作符优先级高时，先计算，再将计算结果压入栈
                    Pop_Sq(&OPTR, &theta);
                    Pop_Sq(&OPND,&b);
                    Push_Sq(&OPND,Operate(a,theta,b));
                    break;//这里没有读字符，c保留的还是刚才读到的字符
            }

        }

    }
    return GetTop_OPTR(OPND);
}

OperatorType GetTop_OPTR(SqStack OPTR)
{
    SElemType_Sq e;

    GetTop_Sq(OPTR,&e);

    return e;

}

int In(SElemType_Sq c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return TRUE;
        default:
            return FALSE;

    }
}

OperatorType Precede(OperatorType o1,OperatorType o2)
{
    OperatorType f;

    switch (o2)
    {
        case '+':
        case '-':
            if(o1=='('||o1=='#')
                f = '<';
            else
                f = '>';
            break;

        case '*':
        case '/':
            if(o1=='*'||o1=='/'||o1==')')
                f='>';
            else
                f='<';
            break;

        case '(':
            if(o1==')')
            {
                printf("括号匹配错误！\n");
                exit(ERROR);
            }
            else
                f = '<';
            break;

        case ')':
            switch(o1)
            {
                case '(':
                    f = '=';
                    break;
                case '#':
                    printf("输入了错误的括号！\n");
                    exit(ERROR);
                default:
                    f = '>';
            }
            break;
        case '#':
            switch (o1)
            {
                case'#':
                    f = '=';
                case '(':
                    printf("有多余括号!\n");
                    exit(ERROR);
                default:
                    f = '>';
            }
    }
    return  f;
}

OperandType Operate(OperandType a,OperatorType theta,OperandType b)
{
    int x,y,z;

    x = a - 48;
    y = b - 48;

    switch (theta)
    {
        case '+':
            return x+y+48;
            break;
        case '-':
            return x-y+48;
            break;
        case '*':
            return x*y+48;
            break;
        case '/':
            return x/y+48;
            break;
    }
}

#endif

//

