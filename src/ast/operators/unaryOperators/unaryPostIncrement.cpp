#include "unaryPostIncrement.hpp"

void UnaryPostIncrement::printC(std::ostream &os) const
{
	os << "(" << getOperand() << ")++";
}