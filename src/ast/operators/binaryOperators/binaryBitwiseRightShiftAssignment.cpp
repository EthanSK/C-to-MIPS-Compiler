#include "binaryBitwiseRightShiftAssignment.hpp"

void BinaryBitwiseRightShiftAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " >>= " << getRight() << ")";
}