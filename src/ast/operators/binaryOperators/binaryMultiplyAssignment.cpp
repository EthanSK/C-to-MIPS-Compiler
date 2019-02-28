#include "binaryMultiplyAssignment.hpp"

void BinaryMultiplyAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " *= " << getRight() << ")";
}