#include "functionDeclaration.hpp"

FunctionDeclaration::FunctionDeclaration(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters) : name(_name), primitiveType(_primitiveType)
{
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