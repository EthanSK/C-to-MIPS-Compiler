#include "variableDeclaration.hpp"

VariableDeclaration::VariableDeclaration(StatementPtr primitiveType, std::string name) : _name(name)
{
    branches.push_back(primitiveType);
}

StatementPtr VariableDeclaration::getType() const
{
    return branches[0];
}

void VariableDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << _name;
}

void VariableDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << _name;
}