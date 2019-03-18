#include "variableDeclarator.hpp"
#include <sstream>

VariableDeclarator::VariableDeclarator(StatementPtr identifier)
{
    branches.push_back(identifier);
}  

StatementPtr VariableDeclarator::getIdentifier() const{
    return branches[0];
}

std::string VariableDeclarator::getIdentifierName() const{
    std::stringstream ss;
    ss << getIdentifier();
    return ss.str();
}

void VariableDeclarator::printC(std::ostream &os) const
{
    os << getIdentifier();
} 

void VariableDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getIdentifier()->generatePython(os, context, scopeDepth);
}