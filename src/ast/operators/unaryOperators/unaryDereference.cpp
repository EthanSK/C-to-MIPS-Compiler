#include "unaryDereference.hpp"

void unaryDereference::printCode(std::ostream &os) const
{
	os << "*(" << getOperand() << ")";
}