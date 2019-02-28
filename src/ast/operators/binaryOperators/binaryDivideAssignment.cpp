#include "binaryDivideAssignment.hpp"

void BinaryDivideAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " /= " << getRight() << ")";
}