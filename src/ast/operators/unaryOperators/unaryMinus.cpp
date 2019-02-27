#include "unaryMinus.hpp"

void UnaryMinus::printCode(std::ostream &os) const
{
	os << "-(" << getOperand() << ")";
}