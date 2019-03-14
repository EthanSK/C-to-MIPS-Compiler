#include "pointerType.hpp"

PointerType::PointerType(StatementPtr child)
{
    branches.push_back(child);
}

StatementPtr PointerType::getChild() const
{
    return branches[0];
}

void PointerType::printC(std::ostream &os) const
{
    os << getChild() << " *";
}