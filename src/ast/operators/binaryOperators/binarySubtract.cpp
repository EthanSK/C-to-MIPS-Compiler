#include "binarySubtract.hpp"

void BinarySubtract::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " - " << getRight() << ")";
}