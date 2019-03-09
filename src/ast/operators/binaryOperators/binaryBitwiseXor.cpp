#include "binaryBitwiseXor.hpp"

void BinaryBitwiseXor::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " ^ " << getRight() << ")";
}