#include "binaryLogicalOr.hpp"

void BinaryLogicalOr::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " || " << getRight() << ")";
}