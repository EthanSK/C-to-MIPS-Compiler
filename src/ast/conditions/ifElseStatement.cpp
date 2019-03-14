#include "ifElseStatement.hpp"

IfElseStatement::IfElseStatement(StatementPtr condition, StatementPtr ifScopeBlock, StatementPtr elseScopeBlock){
    branches.push_back(condition);
    branches.push_back(ifScopeBlock);
    branches.push_back(elseScopeBlock);
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
    os << "if (" << getCondition() << ")" << getIfScopeBlock() << std::endl << "else" << getElseScopeBlock();//the scopeBlock printC is repsonsible for printing the { } with new lines
}  

void IfElseStatement::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    context.indentStream(os, scopeDepth);
    os << "if ";
    getCondition()->generatePython(os, context, scopeDepth);
    os << ":";

    os << std::endl;
    getIfScopeBlock()->generatePython(os, context, scopeDepth + 1);

    context.indentStream(os, scopeDepth);
    os << "else:" << std::endl;
    getElseScopeBlock()->generatePython(os, context, scopeDepth + 1);
}

{
if ((10 >= (7 + 7.7f)))
{
("pink" == "purple");
}
else
{
if ((3 <= (1.374 + 7.7f)))
{
("lost" != "dizzy");
}
else
{
};
};
}