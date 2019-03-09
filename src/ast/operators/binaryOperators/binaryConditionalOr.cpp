#include "binaryConditionalOr.hpp"

void BinaryConditionalOr::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " || " << getRight() << ")";
}