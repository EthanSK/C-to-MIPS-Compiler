#include "primitiveVariable.hpp"

std::string PrimitiveVariableDeclaration::typeToString() const
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

void PrimitiveVariableDeclaration::printC(std::ostream &os) const
{
    os << typeToString() << " " << name;
}