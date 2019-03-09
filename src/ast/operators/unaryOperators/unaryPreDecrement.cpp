#include "unaryPreDecrement.hpp"

void UnaryPreDecrement::printC(std::ostream &os) const
{
	os << "--(" << getOperand() << ")";
}