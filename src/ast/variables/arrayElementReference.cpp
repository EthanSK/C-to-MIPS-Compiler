#include "arrayElementReference.hpp"

void ArrayElementReference::printC(std::ostream &os) const
{
    os << _name << "[" << index << "]";
}