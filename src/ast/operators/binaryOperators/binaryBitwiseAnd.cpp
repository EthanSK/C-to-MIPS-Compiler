#include "binaryBitwiseAnd.hpp"

void BinaryBitwiseAnd::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " & " << getRight() << ")";
}