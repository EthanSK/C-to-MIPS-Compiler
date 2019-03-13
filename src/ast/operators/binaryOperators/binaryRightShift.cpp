#include "binaryRightShift.hpp"

void BinaryRightShift::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " >> " << getRight() << ")";
}