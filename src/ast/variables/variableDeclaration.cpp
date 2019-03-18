#include "variableDeclaration.hpp"

VariableDeclaration::VariableDeclaration(StatementPtr primitiveType, StatementPtr name)
{
    branches.push_back(primitiveType);
    branches.push_back(name);
}

StatementPtr VariableDeclaration::getType() const
{
    return branches[0];
}

StatementPtr VariableDeclaration::getName() const
{
    return branches[1];
}

void VariableDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << getName();
}

void VariableDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    if (scopeDepth == 0)
    {
        const Identifier* identifier = reinterpret_cast<const Identifier*>(getName());
        context.registerGlobal(identifier->getName());
    }
    getName()->generatePython(os, context, scopeDepth);
}