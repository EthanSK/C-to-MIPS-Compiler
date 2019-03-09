#include "binaryBitwiseOrAssignment.hpp"

void BinaryBitwiseOrAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " |= " << getRight() << ")";
}