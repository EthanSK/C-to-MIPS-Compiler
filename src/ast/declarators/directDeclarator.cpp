#include "directDeclarator.hpp"
#include <sstream>

DirectDeclarator::DirectDeclarator(StatementPtr identifier)
{
    branches.push_back(identifier);
}  

StatementPtr DirectDeclarator::getIdentifier() const{
    return branches[0];
}

std::string DirectDeclarator::getIdentifierName() const{
    std::stringstream ss;
    ss << getIdentifier();
    return ss.str();
}

void DirectDeclarator::printC(std::ostream &os) const
{
    os << getIdentifier();
} 

void DirectDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    if (scopeDepth == 0) { context.registerGlobal(getIdentifierName()); }
    getIdentifier()->generatePython(os, context, scopeDepth);
}