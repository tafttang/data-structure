//
// Created by El Fenomeno on 2017/10/25.
//

#ifndef INC_16_EXPRESSION_EXPRESSION_H
#define INC_16_EXPRESSION_EXPRESSION_H

#include <stdio.h>

/*类型定义*/

#include "../12 SequenceStack/SequenceStack.c"

typedef SElemType_Sq OperandType;
typedef SElemType_Sq OperatorType;

//01 3.4表达式求值，假设表达式中操作数均只有一位
OperandType EvaluateExpression(char exp[]);

//02 获取操作符栈的栈顶元素
OperatorType GetTop_OPTR(SqStack OPTR);

//03 判断c是否属于操作符集
int In(SElemType_Sq c);

//04 判断栈中的操作符o1与表达式中的操作符o2的优先级
OperatorType Precede(OperatorType o1,OperatorType o2);

//05 计算表达式的值
OperandType Operate(OperandType a,OperatorType theta,OperandType b);

#endif //INC_16_EXPRESSION_EXPRESSION_H
