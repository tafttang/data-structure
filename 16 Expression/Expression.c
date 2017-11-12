//
// Created by El Fenomeno on 2017/10/25.

#ifndef EXPRESSION_C
#define EXPRESSION_C

#include "Expression.h"

//01 3.4���ʽ��ֵ��������ʽ�в�������ֻ��һλ
OperandType EvaluateExpression(char exp[])
{//��exp������ʽ
    SqStack OPTR,OPND;//����ջ������ջ
    SElemType_Sq e,ch;
    OperatorType theta,x;//����
    OperandType a,b;//����
    int i;

    InitStack_Sq(&OPTR);
    Push_Sq(&OPTR,'#');
    InitStack_Sq(&OPND);

    i = 0;
    ch = exp[i++];
    while(ch!='#'||GetTop_OPTR(OPTR)!='#')
    {
        if(!In(ch))
        {//c���Ƿ�������ջ
            Push_Sq(&OPND,ch);
            ch = exp[i++];
        }
        else
        {
            switch(Precede(GetTop_OPTR(OPTR),ch))
            {
                case '<'://ջ�з������ȼ��ͣ�������ջ
                    Push_Sq(&OPTR,ch);
                    ch = exp[i++];
                    break;

                case '='://���ȼ����ʱ��˵���������ţ���Ҫ������
                    Pop_Sq(&OPTR,&x);
                    ch = exp[i++];
                    break;
                case '>'://ջ�в��������ȼ���ʱ���ȼ��㣬�ٽ�������ѹ��ջ
                    Pop_Sq(&OPTR, &theta);
                    Pop_Sq(&OPND,&b);
                    Push_Sq(&OPND,Operate(a,theta,b));
                    break;//����û�ж��ַ���c�����Ļ��ǸղŶ������ַ�
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
                printf("����ƥ�����\n");
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
                    printf("�����˴�������ţ�\n");
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
                    printf("�ж�������!\n");
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

