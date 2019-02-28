#include "binaryIsEqualTo.hpp"

void BinaryIsEqualTo::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " == " << getRight() << ")";
}