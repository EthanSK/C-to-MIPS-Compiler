#include "pointerVariableDeclaration.hpp"

void PointerVariableDeclaration::printC(std::ostream &os) const
{
    std::string type = primitiveTypeToString();
    os << type << " *" << name;
}