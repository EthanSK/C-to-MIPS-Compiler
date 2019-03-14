#include "unaryOperator.hpp"

UnaryOperator::UnaryOperator(StatementPtr operand)
{
        branches.push_back(operand);
} 

StatementPtr UnaryOperator::getOperand() const
{
        return branches[0];
}