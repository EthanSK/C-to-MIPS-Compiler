#include "pointerVariableDeclaration.hpp"

PrimitiveType PointerVariableDeclaration::getPrimitiveType() const
{
    return primitiveType;
}
void PointerVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariableDeclaration(primitiveType, "tmpName").primitiveTypeToString();
    os << type << " *" << name;
}