#include "binaryIsNotEqualTo.hpp"

void BinaryIsNotEqualTo::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " != " << getRight() << ")";
}