#include "primitiveVariableDeclaration.hpp"


std::string PrimitiveVariableDeclaration::primitiveTypeToString() const
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

void PrimitiveVariableDeclaration::printC(std::ostream &os) const
{
    os << primitiveTypeToString() << " " << name;
} 