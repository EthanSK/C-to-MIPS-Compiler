#include "binaryDivisionAssignment.hpp"

void BinaryDivisionAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " /= " << getRight() << ")";
}