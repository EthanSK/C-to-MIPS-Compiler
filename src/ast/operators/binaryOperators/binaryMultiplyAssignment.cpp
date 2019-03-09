#include "binaryMultiplyAssignment.hpp"

void BinaryMultiplyAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " *= " << getRight() << ")";
}