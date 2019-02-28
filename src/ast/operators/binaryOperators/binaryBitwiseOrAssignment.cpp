#include "binaryBitwiseOrAssignment.hpp"

void BinaryBitwiseOrAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " |= " << getRight() << ")";
}