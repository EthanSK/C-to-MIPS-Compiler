#include "arrayElementReference.hpp"

int ArrayElementReference::getIndex() const
{
    return index;
}

void ArrayElementReference::printC(std::ostream &os) const
{
    os << name << "[" << getIndex() << "]";
}