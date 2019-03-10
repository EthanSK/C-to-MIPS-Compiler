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

void PrimitiveVariable::printC(std::ostream &os) const
{
    if (branches.size() > 0) //then we know it was given a value at declaration
    {
        os << typeToString() << " " << name << " = " << branches[0];
    }
    else
    {
        os << typeToString() << " " << name;
    }
}