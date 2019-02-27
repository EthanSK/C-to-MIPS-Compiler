#include "unaryPreDecrement.hpp"

void UnaryPreDecrement::printCode(std::ostream &os) const
{
	os << "--(" << getOperand() << ")";
}