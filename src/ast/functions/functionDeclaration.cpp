#include "functionDeclaration.hpp"
#include "variableDeclaration.hpp"

FunctionDeclaration::FunctionDeclaration(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters, bool _isPointer, bool _isExtern) : name(_name), primitiveType(_primitiveType), isPointer(_isPointer), isExtern(_isExtern)
{
    branches[0] = parameters;
}

StatementPtr FunctionDeclaration::getParameters() const
{
    return branches[0];
}

void FunctionDeclaration::printC(std::ostream &os) const
{
    std::string primitiveTypeString = VariableDeclaration(primitiveType, name, isPointer, isExtern).primitiveTypeToString();
    if (isPointer)
    {
        os << primitiveTypeString << " *" << name << getParameters();
    }
    else if (isExtern)
    {
        os << "extern " << primitiveTypeString << " *" << name << getParameters();
    }
    else
    {
        os << primitiveTypeString << name << getParameters();
    }
}