#include "binaryBitwiseOr.hpp"

void BinaryBitwiseOr::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " | " << getRight() << ")";
}