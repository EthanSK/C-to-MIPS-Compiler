#include "binaryLessThanOrEqualTo.hpp"

void BinaryLessThanOrEqualTo::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " <= " << getRight() << ")";
}