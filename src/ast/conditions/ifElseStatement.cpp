#include "ifStatement.hpp"

IfElseStatement::IfElseStatement(StatementPtr condition, StatementPtr ifScopeBlock, StatementPtr elseScopeBlock){
    branches[0] = condition;
    branches[1] = ifScopeBlock;
    branches[2] = elseScopeBlock;
}

StatementPtr IfElseStatement::getCondition() const{
    return branches[0];
}
StatementPtr IfElseStatement::getIfScopeBlock() const{
    return branches[1];
}
StatementPtr IfElseStatement::getElseScopeBlock() const{
    return branches[2];
}
void IfElseStatement::printC(std::ostream &os) const
{
    os << "if (" << getCondition() << ")" << getIfScopeBlock() << "else" << getElseScopeBlock();//the scopeBlock printC is repsonsible for printing the { } with new lines
}  