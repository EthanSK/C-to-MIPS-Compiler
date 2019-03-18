#include "forLoop.hpp"

ForLoop::ForLoop(StatementPtr init, StatementPtr condition, StatementPtr increment, StatementPtr scopeBlock)
{
    branches.push_back(init);
    branches.push_back(condition);
    branches.push_back(increment);
    branches.push_back(scopeBlock);
} 
StatementPtr ForLoop::getInit() const
{
    return branches[0];
}
StatementPtr ForLoop::getCondition() const
{
    return branches[1];
}
StatementPtr ForLoop::getIncrement() const
{
    return branches[2];
}
StatementPtr ForLoop::getScopeBlock() const
{
    return branches[3];
}

void ForLoop::printC(std::ostream &os) const
{
    os << "for (" << getInit() << "; " << getCondition() << "; " << getIncrement() << ")" << getScopeBlock();
}