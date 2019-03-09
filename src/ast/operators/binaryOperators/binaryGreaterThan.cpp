#include "binaryGreaterThan.hpp"

void BinaryGreaterThan::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " > " << getRight() << ")";
}