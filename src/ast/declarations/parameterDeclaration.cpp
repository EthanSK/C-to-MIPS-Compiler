#include "parameterDeclaration.hpp"

ParameterDeclaration::ParameterDeclaration(StatementPtr type, StatementPtr decl)
{
    branches.push_back(type);
    branches.push_back(decl);
}

StatementPtr ParameterDeclaration::getType() const
{
    return branches[0];
}

StatementPtr ParameterDeclaration::getDecl() const
{
    return branches[1];
}

void ParameterDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << getDecl();
}

void ParameterDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getDecl()->generatePython(os, context, scopeDepth);
}