#include "unaryPostDecrement.hpp"

void UnaryPostDecrement::printCode(std::ostream &os) const
{
	os << "(" << getOperand() << ")--";
}