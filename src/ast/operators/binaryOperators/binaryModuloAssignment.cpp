#include "binaryModuloAssignment.hpp"

void BinaryModuloAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " %= " << getRight() << ")";
}