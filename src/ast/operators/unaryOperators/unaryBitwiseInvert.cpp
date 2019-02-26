#include "unaryBitwiseInvert.hpp"

void UnaryBitwiseInvert::printCode(std::ostream &os) const override
{
	os << "~(" << getOperand() << ")";
}