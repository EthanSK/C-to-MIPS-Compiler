#include "unaryOperator.hpp"

UnaryOperator::UnaryOperator(StatementPtr operand)
{
        branches[0] = operand;
} 

StatementPtr UnaryOperator::getOperand() const
{
        return branches[0];
}