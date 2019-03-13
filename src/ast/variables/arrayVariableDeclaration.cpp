#include "arrayVariableDeclaration.hpp"

int ArrayVariableDeclaration::getSize() const
{
    return size;
}
PrimitiveType ArrayVariableDeclaration::getPrimitiveType() const
{
    return primitiveType;
}

void ArrayVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariableDeclaration(primitiveType, "tmpName").primitiveTypeToString();
    os << type << " " << name << "[" << size << "]";
}