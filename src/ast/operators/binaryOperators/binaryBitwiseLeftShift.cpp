#include "binaryBitwiseLeftShift.hpp"

void BinaryBitwiseLeftShift::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " << " << getRight() << ")";
}