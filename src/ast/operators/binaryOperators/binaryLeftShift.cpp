#include "binaryLeftShift.hpp"

void BinaryLeftShift::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " << " << getRight() << ")";
}