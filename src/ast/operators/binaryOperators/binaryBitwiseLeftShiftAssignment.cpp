#include "binaryBitwiseLeftShiftAssignment.hpp"

void BinaryBitwiseLeftShiftAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " <<= " << getRight() << ")";
}