#include "arrayVariableDeclaration.hpp"

void ArrayVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariableDeclaration(elementType, "tmpName").typeToString();
    os << type << " " << name << "[" << size << "]";
} 