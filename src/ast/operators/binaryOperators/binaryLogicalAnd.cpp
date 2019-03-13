#include "binaryLogicalAnd.hpp"

void BinaryLogicalAnd::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " && " << getRight() << ")";
}