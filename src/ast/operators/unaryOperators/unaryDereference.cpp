#include "unaryDereference.hpp"

void UnaryDereference::printC(std::ostream &os) const
{
	os << "*(" << getOperand() << ")";
}