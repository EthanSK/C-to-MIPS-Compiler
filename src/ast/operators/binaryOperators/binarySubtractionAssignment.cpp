#include "binarySubtractionAssignment.hpp"

void BinarySubtractionAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " -= " << getRight() << ")";
}