#include "arrayVariableDeclaration.hpp"

PrimitiveType ArrayVariableDeclaration::getPrimitiveType() const
{
    return primitiveType;
}

void ArrayVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariableDeclaration(primitiveType, "tmpName").primitiveTypeToString();
    os << type << " " << name << "[" << size << "]";
}