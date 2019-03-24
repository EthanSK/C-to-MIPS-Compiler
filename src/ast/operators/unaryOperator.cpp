#include "unaryOperator.hpp"
#include "utils.hpp"

UnaryOperator::UnaryOperator(StatementPtr operand)
{
        branches.push_back(operand);
} 

StatementPtr UnaryOperator::getOperand() const
{
        return branches[0];
}

RValuePtr UnaryOperator::getOperandR() const
{
        return Utils::tryCast<RValue>(getOperand(), "operand of a unary function must be an rvalue");
}

bool UnaryOperator::isConstant() const { return getOperandR()->isConstant(); }