#include "binaryModulo.hpp"

void BinaryModulo::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " % " << getRight() << ")";
}