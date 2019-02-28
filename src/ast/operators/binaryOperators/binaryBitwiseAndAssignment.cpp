#include "binaryBitwiseAndAssignment.hpp"

void BinaryBitwiseAndAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " &= " << getRight() << ")";
}