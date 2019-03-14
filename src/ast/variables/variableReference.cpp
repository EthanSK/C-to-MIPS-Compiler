#include "variableReference.hpp"

VariableReference::VariableReference(std::string name)
{
    this->name = name;
}

void VariableReference::printC(std::ostream &os) const
{
    os << name;
}