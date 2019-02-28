#include "binaryModulo.hpp"

void BinaryModulo::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " % " << getRight() << ")";
}