#include "initDeclarator.hpp"

InitDeclarator::InitDeclarator(StatementPtr declarator, StatementPtr initializer)
{
    branches.push_back(declarator);
    branches.push_back(initializer);
}
  
DeclaratorPtr InitDeclarator::getDeclarator() const
{
    return reinterpret_cast<DeclaratorPtr>(branches[0]);
}

StatementPtr InitDeclarator::getInitializer() const
{
    return branches[1];
}
  
std::string InitDeclarator::getIdentifierName() const
{
    return getDeclarator()->getIdentifierName();
}

void InitDeclarator::printC(std::ostream &os) const
{
    os << getDeclarator() << " = " << getInitializer();
}

void InitDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getDeclarator()->generatePython(os, context, scopeDepth);
    os << " = ";
    getInitializer()->generatePython(os, context, scopeDepth);
}