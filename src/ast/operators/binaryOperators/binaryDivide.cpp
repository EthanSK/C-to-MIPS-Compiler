#include "binaryDivide.hpp"

void BinaryDivide::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " / " << getRight() << ")";
}