#include "unaryNot.hpp"

void UnaryNot::printCode(std::ostream &os) const override
{
	os << "!(" << getOperand() << ")";
}