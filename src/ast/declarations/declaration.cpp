#include "declaration.hpp"

Declaration::Declaration(StatementPtr type, DeclaratorListPtr declList)
{
    branches.push_back(type);
    branches.push_back(declList);
}

StatementPtr Declaration::getType() const
{
    return branches[0];
}

DeclaratorListPtr Declaration::getDeclList() const
{
    return reinterpret_cast<DeclaratorListPtr>(branches[1]);
}

void Declaration::printC(std::ostream &os) const
{
    os << getType() << " " << getDeclList();
}

void Declaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getDeclList()->generatePython(os, context, scopeDepth);
}