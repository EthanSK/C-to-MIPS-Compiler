#include "forLoop.hpp"

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
    os << "for (" << getInit() << "; " << getCondition() << "; " << getIncrement() << " )" << getScopeBlock();
} 