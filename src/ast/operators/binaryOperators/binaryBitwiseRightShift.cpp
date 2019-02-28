#include "binaryBitwiseRightShift.hpp"

void BinaryBitwiseRightShift::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " >> " << getRight() << ")";
}