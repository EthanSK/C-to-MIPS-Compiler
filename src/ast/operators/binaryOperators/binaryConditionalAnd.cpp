#include "binaryConditionalAnd.hpp"

void BinaryConditionalAnd::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " && " << getRight() << ")";
}