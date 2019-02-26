#include "unaryBitwiseInvert.hpp"

void unaryBitwiseInvert::printCode(std::ostream &os) const override
{
	os << "~(" << getOperand() << ")";
}