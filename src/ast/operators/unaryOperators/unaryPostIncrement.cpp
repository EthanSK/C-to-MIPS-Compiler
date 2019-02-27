#include "unaryPostIncrement.hpp"

void UnaryPostIncrement::printCode(std::ostream &os) const
{
	os << "(" << getOperand() << ")++";
}