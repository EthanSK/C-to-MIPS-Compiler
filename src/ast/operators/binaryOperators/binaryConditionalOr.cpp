#include "binaryConditionalOr.hpp"

void BinaryConditionalOr::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " || " << getRight() << ")";
}