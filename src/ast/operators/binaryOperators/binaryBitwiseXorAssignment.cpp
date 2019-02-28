#include "binaryBitwiseXorAssignment.hpp"

void BinaryBitwiseXorAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " ^= " << getRight() << ")";
}