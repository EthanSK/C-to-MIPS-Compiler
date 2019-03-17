#include "arrayElementReference.hpp"

ArrayElementReference::ArrayElementReference(std::string name, StatementPtr index) : VariableReference(name)
{
    branches.push_back(index);
}

StatementPtr ArrayElementReference::getIndex() const
{
    return branches[0];
}

void ArrayElementReference::printC(std::ostream &os) const
{
    os << _name << "[" << getIndex() << "]";
}