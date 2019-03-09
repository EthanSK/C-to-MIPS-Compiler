#include "binaryBitwiseRightShift.hpp"

void BinaryBitwiseRightShift::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " >> " << getRight() << ")";
}