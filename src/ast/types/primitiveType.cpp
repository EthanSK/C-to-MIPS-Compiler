#include "primitiveType.hpp"

void PrimitiveType::printC(std::ostream &os) const
{
    os << primitiveTypeToString();
}

std::string PrimitiveType::primitiveTypeToString() const
{
    switch (_type)
    {
    case PrimitiveType::_void:
        return "void";
    case PrimitiveType::_int:
        return "int";
    case PrimitiveType::_float:
        return "float";
    case PrimitiveType::_double:
        return "double";
    case PrimitiveType::_char:
        return "char";
    case PrimitiveType::_signed:
        return "signed";
    case PrimitiveType::_unsigned:
        return "unsigned";
    case PrimitiveType::_long:
        return "long";
    default:
        return "UNKNOWN TYPE";
    }
}