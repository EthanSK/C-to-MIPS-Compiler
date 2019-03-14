#include "variableReference.hpp"

VariableReference::VariableReference(std::string name)
{
    _name = name;
}

void VariableReference::printC(std::ostream &os) const
{
    os << _name;
}

void VariableReference::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << _name;
}