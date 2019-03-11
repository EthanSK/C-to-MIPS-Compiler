#include "ifStatement.hpp"

StatementPtr IfStatement::getCondition() const{
    return branches[0];
}
StatementPtr IfStatement::getIfScopeBlock() const{
    return branches[1];
}
StatementPtr IfStatement::getElseScopeBlock() const{
    return branches[2];
}
void IfStatement::printC(std::ostream &os) const
{
    os << "if (" << getCondition() << ")" << getIfScopeBlock() << "else" << getElseScopeBlock();//the scopeBlock printC is repsonsible for printing the { } with new lines
}  