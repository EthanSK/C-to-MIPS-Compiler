#include "unaryMinus.hpp"

void UnaryMinus::printC(std::ostream &os) const
{
	os << "-(" << getOperand() << ")";
}