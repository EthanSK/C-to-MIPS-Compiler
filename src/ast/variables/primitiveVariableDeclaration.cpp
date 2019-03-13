#include "primitiveVariableDeclaration.hpp"

std::string PrimitiveVariableDeclaration::typeToString() const
{
    switch (type)
    {
    case PrimitiveType::_int:
        return "int";
    case PrimitiveType::_float:
        return "float";
    case PrimitiveType::_double:
        return "double";
    case PrimitiveType::_char:
        return "char";
    case PrimitiveType::_unsignedChar:
        return "unsigned char";
    case PrimitiveType::_signedChar:
        return "signed char";
    case PrimitiveType::_unsignedInt:
        return "unsigned int";
    case PrimitiveType::_short:
        return "short";
    case PrimitiveType::_unsignedShort:
        return "unsigned short";
    case PrimitiveType::_long:
        return "long";
    case PrimitiveType::_unsignedLong:
        return "unsigned long";
    case PrimitiveType::_longDouble:
        return "long double";
    default:
        return "UNKNOWN TYPE";
    }
}

void PrimitiveVariableDeclaration::printC(std::ostream &os) const
{
    os << typeToString() << " " << name;
}