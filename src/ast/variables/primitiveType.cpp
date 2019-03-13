#include "primitiveType.hpp"

std::string PrimitiveType::typeToString() const
{
    switch (type)
    {
    case Type::_int:
        return "int";
    case Type::_float:
        return "float";
    case Type::_double:
        return "double";
    case Type::_char:
        return "char";
    case Type::_unsigned:
        return "unsigned";
    default:
        return "UNKNOWN TYPE";
    }
}

void PrimitiveType::printC(std::ostream &os) const
{
    os << typeToString() << " " << name;
}