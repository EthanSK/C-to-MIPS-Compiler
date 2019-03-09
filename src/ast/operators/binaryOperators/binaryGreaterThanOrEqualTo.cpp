#include "binaryGreaterThanOrEqualTo.hpp"

void BinaryGreaterThanOrEqualTo::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " >= " << getRight() << ")";
}