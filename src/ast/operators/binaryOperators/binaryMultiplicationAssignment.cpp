#include "binaryMultiplicationAssignment.hpp"

void BinaryMultiplicationAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " *= " << getRight() << ")";
}