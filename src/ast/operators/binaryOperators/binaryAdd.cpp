#include "binaryAdd.hpp"

void BinaryAdd::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " + " << getRight() << ")";
}