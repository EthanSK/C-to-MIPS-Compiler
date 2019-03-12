#include "binaryOperator.hpp"

BinaryOperator::BinaryOperator(StatementPtr left, StatementPtr right)
{
        branches[0] = left;
        branches[1] = right;
}

StatementPtr BinaryOperator::getLeft() const
{
        return branches[0];
}

StatementPtr BinaryOperator::getRight() const
{
        return branches[1];
}