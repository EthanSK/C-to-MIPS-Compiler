#include "binaryLessThanOrEqualTo.hpp"

void BinaryLessThanOrEqualTo::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " <= " << getRight() << ")";
}