#include "qualifiedType.hpp"

QualifiedType::QualifiedType(StatementPtr child, StatementPtr qualifier)
{
    branches.push_back(child);
    branches.push_back(qualifier);
}

TypePtr QualifiedType::getChild() const
{
    return reinterpret_cast<TypePtr>(branches[0]);
}

StatementPtr QualifiedType::getQualifier() const
{
    return branches[1];
}

void QualifiedType::printC(std::ostream &os) const
{
    os << getQualifier() << " " << getChild();
}