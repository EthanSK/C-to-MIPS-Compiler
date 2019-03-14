#include "unaryBitwiseInvert.hpp"

void UnaryBitwiseInvert::printC(std::ostream &os) const
{
	os << "~(" << getOperand() << ")";
}