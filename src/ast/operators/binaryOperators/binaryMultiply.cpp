#include "binaryMultiply.hpp"

void BinaryMultiply::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " * " << getRight() << ")";
}