#include "binaryAdd.hpp"

void BinaryAdd::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " + " << getRight() << ")";
}