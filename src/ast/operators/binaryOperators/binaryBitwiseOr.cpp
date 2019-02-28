#include "binaryBitwiseOr.hpp"

void BinaryBitwiseOr::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " | " << getRight() << ")";
}