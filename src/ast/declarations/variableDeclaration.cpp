#include "variableDeclaration.hpp"

VariableDeclaration::VariableDeclaration(StatementPtr type, NodeListPtr initList)
{
    branches.push_back(type);
    branches.push_back(initList);
}

StatementPtr VariableDeclaration::getType() const
{
    return branches[0];
}

StatementPtr VariableDeclaration::getInitList() const
{
    return branches[1];
}

void VariableDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << getInitList();
}

void VariableDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getInitList()->generatePython(os, context, scopeDepth);
}