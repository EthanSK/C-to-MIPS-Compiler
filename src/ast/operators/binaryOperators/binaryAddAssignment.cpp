#include "binaryAddAssignment.hpp"

void BinaryAddAssignment::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " += " << getRight() << ")";
}