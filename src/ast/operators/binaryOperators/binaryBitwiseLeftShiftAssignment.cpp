#include "binaryBitwiseLeftShiftAssignment.hpp"

void BinaryBitwiseLeftShiftAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " <<= " << getRight() << ")";
}