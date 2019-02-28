#include "binaryLessThan.hpp"

void BinaryLessThan::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " < " << getRight() << ")";
}