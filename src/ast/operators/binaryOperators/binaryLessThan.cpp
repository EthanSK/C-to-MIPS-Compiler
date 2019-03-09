#include "binaryLessThan.hpp"

void BinaryLessThan::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " < " << getRight() << ")";
}