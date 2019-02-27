#include "unaryPreIncrement.hpp"

void UnaryPreIncrement::printCode(std::ostream &os) const
{
	os << "++(" << getOperand() << ")";
}