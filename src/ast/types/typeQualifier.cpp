#include "typeQualifier.hpp"

void TypeQualifier::printC(std::ostream &os) const
{
    os << typeQualifierToString();
}

std::string TypeQualifier::typeQualifierToString() const
{
    switch (_type)
    {
    case TypeQualifierEnum::_const:
        return "const";
    case TypeQualifierEnum::_volatile:
        return "volatile";
    default:
        return "UNKNOWN TYPE QUALIFIER";
    }
}