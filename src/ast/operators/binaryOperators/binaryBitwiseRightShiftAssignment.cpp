#include "binaryBitwiseRightShiftAssignment.hpp"

void BinaryBitwiseRightShiftAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " >>= " << getRight() << ")";
}