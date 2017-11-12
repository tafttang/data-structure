//

// Created by El Fenomeno on 2017/10/25.
#include "Expression.cpp"

int main(int argc,char **argv)
{
    char opnd;
    char *exp = "1+2*(5-3)-6/2+4#";

    opnd = EvaluateExpression(exp);

    printf("作为示例，%s的计算结果为:%c\n",exp,opnd);

    printf("\n");

    return 0;
}

//

