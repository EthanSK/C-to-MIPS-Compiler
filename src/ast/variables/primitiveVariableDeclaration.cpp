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
    default:
        return "UNKNOWN TYPE";
    }
}

void PrimitiveVariableDeclaration::printC(std::ostream &os) const
{
    os << typeToString() << " " << name;
}