#include "unaryOperator.hpp"

StatementPtr UnaryOperator::getOperand() const
{
        return branches[0];
} 