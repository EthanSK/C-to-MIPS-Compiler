#include "binaryLeftShiftAssignment.hpp"

void BinaryLeftShiftAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " <<= " << getRight() << ")";
}