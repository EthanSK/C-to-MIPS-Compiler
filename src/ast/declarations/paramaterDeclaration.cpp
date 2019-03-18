#include "paramaterDeclaration.hpp"

ParamaterDeclaration::ParamaterDeclaration(StatementPtr type, StatementPtr identifier)
{
    branches.push_back(type);
    branches.push_back(identifier);
}

StatementPtr ParamaterDeclaration::getType() const
{
    return branches[0];
}

StatementPtr ParamaterDeclaration::getIdentifier() const
{
    return branches[1];
}

void ParamaterDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << getIdentifier();
}

void ParamaterDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getIdentifier()->generatePython(os, context, scopeDepth);
}