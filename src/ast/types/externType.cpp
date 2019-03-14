#include "externType.hpp"

ExternType::ExternType(StatementPtr child)
{
    branches.push_back(child);
}

StatementPtr ExternType::getChild() const
{
    return branches[0];
}

void ExternType::printC(std::ostream &os) const
{
    os << "extern " << getChild();
}