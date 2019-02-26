#include "unaryDereference.hpp"

void unaryDereference::printCode(std::ostream &os) const override
{
	os << "*(" << getOperand() << ")";
}