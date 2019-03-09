#include "binaryMultiply.hpp"

void BinaryMultiply::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " * " << getRight() << ")";
}