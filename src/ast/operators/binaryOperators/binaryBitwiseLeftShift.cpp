#include "binaryBitwiseLeftShift.hpp"

void BinaryBitwiseLeftShift::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " << " << getRight() << ")";
}