#include "binaryBitwiseAnd.hpp"

void BinaryBitwiseAnd::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " & " << getRight() << ")";
}