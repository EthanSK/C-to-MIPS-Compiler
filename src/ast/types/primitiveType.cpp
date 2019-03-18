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

int PrimitiveType::getTypeSize() const
{
   switch (_type)
    {
    case PrimitiveType::_void:
        return 0;
    case PrimitiveType::_int:
        return 4;
    case PrimitiveType::_float:
        return 4;
    case PrimitiveType::_double:
        return 8;
    case PrimitiveType::_char:
        return 1;
    case PrimitiveType::_signed:
        return 4;
    case PrimitiveType::_unsigned:
        return 4;
    case PrimitiveType::_long:
        return 8;
    default:
        return 0;
    } 
}