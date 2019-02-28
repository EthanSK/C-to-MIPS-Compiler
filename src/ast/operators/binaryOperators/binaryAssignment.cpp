#include "binaryAssignment.hpp"

void BinaryAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " = " << getRight() << ")";
}