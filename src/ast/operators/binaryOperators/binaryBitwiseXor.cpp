#include "binaryBitwiseXor.hpp"

void BinaryBitwiseXor::printCode(std::ostream &os) const
{
	os << "(" << getLeft() << " ^ " << getRight() << ")";
}