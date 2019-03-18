#include "pointerType.hpp"

PointerType::PointerType(StatementPtr child)
{
    branches.push_back(child);
}

TypePtr PointerType::getChild() const
{
    return reinterpret_cast<TypePtr>(branches[0]);
}

void PointerType::printC(std::ostream &os) const
{
    os << getChild() << " *";
}

int PointerType::getTypeSize() const { return 4; }