#include "unaryNot.hpp"

void UnaryNot::printC(std::ostream &os) const
{
	os << "!(" << getOperand() << ")";
}