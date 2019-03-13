#include "binaryRightShiftAssignment.hpp"

void BinaryRightShiftAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " >>= " << getRight() << ")";
}