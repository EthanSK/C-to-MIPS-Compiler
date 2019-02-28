#include "binaryGreaterThan.hpp"

void BinaryGreaterThan::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " > " << getRight() << ")";
}