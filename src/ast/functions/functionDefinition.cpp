#include "functionDefinition.hpp"

FunctionDefinition::FunctionDefinition(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters, StatementPtr scopeBlock) : name(_name), primitiveType(_primitiveType)
{
    branches[0] = parameters;
    branches[1] = scopeBlock;
}
StatementPtr FunctionDefinition::getParameters() const
{
    return branches[0];
}
StatementPtr FunctionDefinition::getScopeBlock() const
{
    return branches[1];
}
void FunctionDefinition::printC(std::ostream &os) const
{
    os << name << getParameters();
}