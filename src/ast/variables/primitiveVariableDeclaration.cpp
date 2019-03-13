#include "primitiveVariableDeclaration.hpp"

void PrimitiveVariableDeclaration::printC(std::ostream &os) const
{
    os << primitiveTypeToString() << " " << name;
} 