#include "binarySubtractAssignment.hpp"

void BinarySubtractAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " -= " << getRight() << ")";
}