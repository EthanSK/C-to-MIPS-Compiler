#include "variableDeclaration.hpp"

std::string VariableDeclaration::primitiveTypeToString() const
{
    switch (primitiveType)
    {
    case PrimitiveType::_int:
        return "int";
    case PrimitiveType::_float:
        return "float";
    case PrimitiveType::_double:
        return "double";
    case PrimitiveType::_char:
        return "char";
    case PrimitiveType::_unsigned:
        return "unsigned";
    default:
        return "UNKNOWN TYPE";
    }
}

void VariableDeclaration::printC(std::ostream &os) const
{
    if (isPointer)
    {
        os << primitiveTypeToString() << " *" << name;
    }
    else if (isArray)
    {
        os << primitiveTypeToString() << " " << name << "[" << arraySize << "]";
    }
    else if (isExtern)
    {
        os << "extern " << primitiveTypeToString() << " " << name;
    }else{
        os << primitiveTypeToString() << " " << name;

    }
}
