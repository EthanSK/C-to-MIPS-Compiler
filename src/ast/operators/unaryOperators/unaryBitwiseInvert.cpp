#include "unaryBitwiseInvert.hpp"

void unaryBitwiseInvert::printCode(std::ostream &os) const
{
	os << "~(" << getOperand() << ")";
}