#include "functionDeclaration.hpp"

FunctionDeclaration::FunctionDeclaration(StatementPtr parameters){
    branches[0] = parameters;
}

StatementPtr FunctionDeclaration::getParameters() const
{
    return branches[0];
}
void FunctionDeclaration::printC(std::ostream &os) const
{
    os << name << getParameters();
}