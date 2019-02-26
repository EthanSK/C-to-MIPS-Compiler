#include "unaryDereference.hpp"

void UnaryDereference::printCode(std::ostream &os) const override
{
	os << "*(" << getOperand() << ")";
}