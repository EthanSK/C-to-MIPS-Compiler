#include "arrayVariableDeclaration.hpp"
#include "primitiveVariableDeclaration.hpp"

PrimitiveType ArrayVariableDeclaration::getPrimitiveType() const
{
    return primitiveType;
}

void ArrayVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = primitiveTypeToString();
    os << type << " " << name << "[" << size << "]";
}