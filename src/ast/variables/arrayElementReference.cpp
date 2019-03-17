#include "arrayElementReference.hpp"

ArrayElementReference::ArrayElementReference(StatementPtr arr, StatementPtr index)
{
    branches.push_back(arr);
    branches.push_back(index);
}

StatementPtr ArrayElementReference::getArr() const
{
    return branches[0];
}

StatementPtr ArrayElementReference::getIndex() const
{
    return branches[1];
}

void ArrayElementReference::printC(std::ostream &os) const
{
    os << getArr() << "[" << getIndex() << "]";
}