#include "binaryAddAssignment.hpp"

void BinaryAddAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " += " << getRight() << ")";
}