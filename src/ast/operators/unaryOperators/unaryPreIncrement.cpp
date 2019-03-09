#include "unaryPreIncrement.hpp"

void UnaryPreIncrement::printC(std::ostream &os) const
{
	os << "++(" << getOperand() << ")";
}