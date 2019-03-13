#include "functionDefinition.hpp"
#include "variableDeclaration.hpp"

FunctionDefinition::FunctionDefinition(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters, StatementPtr scopeBlock, bool _isPointer, bool _isExtern) : name(_name), primitiveType(_primitiveType), isPointer(_isPointer), isExtern(_isExtern)
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
    std::string primitiveTypeString = VariableDeclaration(primitiveType, name, isPointer, isExtern).primitiveTypeToString();
    if (isPointer)
    {
        os << primitiveTypeString << " *" << name << getParameters() << getScopeBlock();
    }
    else if (isExtern)
    {
        os << "extern " << primitiveTypeString << " *" << name << getParameters() << getScopeBlock();
    }
    else
    {
        os << primitiveTypeString << name << getParameters() << getScopeBlock();
    }

}