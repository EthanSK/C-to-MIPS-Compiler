#include "pointerVariableDeclaration.hpp"

void PointerVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = PrimitiveVariableDeclaration(primitiveType, "tmpName").primitiveTypeToString();
    os << type << " *" << name;
}