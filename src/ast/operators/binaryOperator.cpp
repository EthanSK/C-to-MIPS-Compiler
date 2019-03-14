#include "binaryOperator.hpp"

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