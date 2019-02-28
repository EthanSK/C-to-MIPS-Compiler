#include "binaryGreaterThanOrEqualTo.hpp"

void BinaryGreaterThanOrEqualTo::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " >= " << getRight() << ")";
}