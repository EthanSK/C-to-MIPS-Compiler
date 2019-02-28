#include "binaryInNotEqualTo.hpp"

void BinaryInNotEqualTo::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " != " << getRight() << ")";
}