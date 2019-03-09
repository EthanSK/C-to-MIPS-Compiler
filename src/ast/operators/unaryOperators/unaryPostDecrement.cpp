#include "unaryPostDecrement.hpp"

void UnaryPostDecrement::printC(std::ostream &os) const
{
	os << "(" << getOperand() << ")--";
}