#include "binarySubtractAssignment.hpp"

void BinarySubtractAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " -= " << getRight() << ")";
}