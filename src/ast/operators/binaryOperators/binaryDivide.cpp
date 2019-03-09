#include "binaryDivide.hpp"

void BinaryDivide::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " / " << getRight() << ")";
}