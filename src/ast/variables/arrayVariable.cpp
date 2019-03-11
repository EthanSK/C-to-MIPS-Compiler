#include "arrayVariable.hpp"

void ArrayVariable::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariable(elementType).typeToString();
    if (branches.size() > 0) //then we know it was given a value at declaration
    {
        os << type << " " << name << " = {";
        for(size_t i = 0; i < branches.size(); i++)
        {
           os << branches[i];
        }
        os << " }";
    }
    else
    {
        os << type << " " << name;
    }
}