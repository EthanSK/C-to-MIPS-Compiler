#include "doWhileLoop.hpp"

DoWhileLoop::DoWhileLoop(StatementPtr scopeBlock, StatementPtr condition){
    branches[0] = scopeBlock;
    branches[1] = condition; 
}
StatementPtr DoWhileLoop::getScopeBlock() const
{
    return branches[0];
}
StatementPtr DoWhileLoop::getCondition() const
{
    return branches[1];
}

void DoWhileLoop::printC(std::ostream &os) const
{
    os << "do" << getScopeBlock() << "while ( " << getCondition() << ")";
}