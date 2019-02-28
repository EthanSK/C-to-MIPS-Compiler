#include "binaryAdditionAssignment.hpp"

void BinaryAdditionAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " += " << getRight() << ")";
}