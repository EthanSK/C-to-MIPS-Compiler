#include "binaryDivideAssignment.hpp"

void BinaryDivideAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " /= " << getRight() << ")";
}