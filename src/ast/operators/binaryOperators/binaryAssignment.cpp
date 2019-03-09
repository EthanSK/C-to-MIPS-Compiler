#include "binaryAssignment.hpp"

void BinaryAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " = " << getRight() << ")";
}