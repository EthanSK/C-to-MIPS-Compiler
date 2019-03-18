#include "functionDeclaration.hpp"
#include "variableDeclaration.hpp"

FunctionDeclaration::FunctionDeclaration(StatementPtr retType, StatementPtr decl)
{
    branches.push_back(retType);
    branches.push_back(decl);
}

StatementPtr FunctionDeclaration::getRetType() const
{
    return branches[0];
}

StatementPtr FunctionDeclaration::getDecl() const
{
    return branches[1];
}

void FunctionDeclaration::printC(std::ostream &os) const
{
    os << getRetType() << " " << getDecl();
}

void FunctionDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "def ";
    getDecl()->generatePython(os, context, scopeDepth);
}