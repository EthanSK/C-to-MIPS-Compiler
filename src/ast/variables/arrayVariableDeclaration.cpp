#include "arrayVariable.hpp"

void ArrayVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariableDeclaration(elementType).typeToString();
    os << type << " " << name << "[" << size << "]";
}