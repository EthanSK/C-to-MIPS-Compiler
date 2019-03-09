#include "binaryConditionalAnd.hpp"

void BinaryConditionalAnd::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " && " << getRight() << ")";
}