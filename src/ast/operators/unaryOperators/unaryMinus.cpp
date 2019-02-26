#include "unaryMinus.hpp"

void UnaryMinus::printCode(std::ostream &os) const override
{
	os << "-(" << getOperand() << ")";
}