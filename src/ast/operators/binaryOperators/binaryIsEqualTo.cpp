#include "binaryIsEqualTo.hpp"

void BinaryIsEqualTo::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " == " << getRight() << ")";
}