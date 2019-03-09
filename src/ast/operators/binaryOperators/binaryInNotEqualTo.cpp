#include "binaryInNotEqualTo.hpp"

void BinaryInNotEqualTo::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " != " << getRight() << ")";
}