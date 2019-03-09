#include "binaryBitwiseXorAssignment.hpp"

void BinaryBitwiseXorAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " ^= " << getRight() << ")";
}