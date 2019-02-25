#include "../../include/ast/binaryOperator.hpp"

StatementPtr BinaryOperator::getLeft() const
{
        return branches[0];
}

StatementPtr BinaryOperator::getRight() const
{
        return branches[1];
}