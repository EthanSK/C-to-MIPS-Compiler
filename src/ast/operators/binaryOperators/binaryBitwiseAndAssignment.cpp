#include "binaryBitwiseAndAssignment.hpp"

void BinaryBitwiseAndAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " &= " << getRight() << ")";
}