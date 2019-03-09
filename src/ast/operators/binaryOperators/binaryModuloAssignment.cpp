#include "binaryModuloAssignment.hpp"

void BinaryModuloAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " %= " << getRight() << ")";
}