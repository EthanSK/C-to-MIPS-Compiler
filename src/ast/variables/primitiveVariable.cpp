#include "primitiveVariable.hpp"

std::string PrimitiveVariable::typeToString() const
{
    switch (type)
    {
    case Type::_int:
        return "int";
    case Type::_float:
        return "float";
    case Type::_double:
        return "double";
    default:
        return "UNKNOWN TYPE";
    }
}