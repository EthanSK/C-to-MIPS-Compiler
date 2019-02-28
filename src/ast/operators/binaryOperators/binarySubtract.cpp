#include "binarySubtract.hpp"

void BinarySubtract::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " - " << getRight() << ")";
}