//

// Created by El Fenomeno on 2017/10/25.
#include "Expression.c"

int main(int argc,char **argv)
{
    char opnd;
    char *exp = "1+2*(5-3)-6/2+4#";

    opnd = EvaluateExpression(exp);

    printf("��Ϊʾ����%s�ļ�����Ϊ:%c\n",exp,opnd);

    printf("\n");

    return 0;
}
