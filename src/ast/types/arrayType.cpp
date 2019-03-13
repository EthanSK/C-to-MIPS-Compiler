#include "arrayType.hpp"

ArrayType::ArrayType(StatementPtr child, int size) : _size(size)
{
    branches.push_back(child);
}

StatementPtr ArrayType::getChild() const
{
    return branches[0];
}

void ArrayType::printC(std::ostream &os) const
{
    os << getChild() << "[" << _size << "]"; //not correct but we can't think of another way that isn't retarded. C is retarded
}