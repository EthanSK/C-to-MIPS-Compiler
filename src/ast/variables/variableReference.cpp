#include "variableReference.hpp"

VariableReference::VariableReference(std::string name)
{
    name = name;
}

void VariableReference::printC(std::ostream &os) const
{
    os << name;
}