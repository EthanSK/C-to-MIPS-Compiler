#include "binaryOperator.hpp"
#include "utils.hpp"

BinaryOperator::BinaryOperator(StatementPtr left, StatementPtr right)
{
        branches.push_back(left);
        branches.push_back(right);
}

StatementPtr BinaryOperator::getLeft() const
{
        return branches[0];
}

StatementPtr BinaryOperator::getRight() const
{
        return branches[1];
}

RValuePtr BinaryOperator::getLeftR() const
{
        return Utils::tryCast<RValue>(getLeft(), "lhs of a binary operator must be an rvalue");
}

RValuePtr BinaryOperator::getRightR() const
{
        return Utils::tryCast<RValue>(getRight(), "rhs of a binary operator must be an rvalue");
}

bool BinaryOperator::isConstant() const
{
        return getLeftR()->isConstant() && getRightR()->isConstant();
}