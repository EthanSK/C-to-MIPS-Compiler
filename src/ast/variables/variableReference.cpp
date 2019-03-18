#include "variableReference.hpp"

VariableReference::VariableReference(StatementPtr name)
{
    branches.push_back(name);
}

StatementPtr VariableReference::getName() const
{
    return branches[0];
}

void VariableReference::printC(std::ostream &os) const
{
    os << getName();
}

void VariableReference::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getName()->generatePython(os, context, scopeDepth);
}