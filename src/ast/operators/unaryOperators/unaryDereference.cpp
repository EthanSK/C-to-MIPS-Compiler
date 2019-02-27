#include "unaryDereference.hpp"

void UnaryDereference::printCode(std::ostream &os) const
{
	os << "*(" << getOperand() << ")";
}