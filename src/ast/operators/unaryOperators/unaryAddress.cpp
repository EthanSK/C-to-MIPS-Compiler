#include "unaryAddress.hpp"

void UnaryAddress::printC(std::ostream &os) const
{
	os << "&(" << getOperand() << ")";
}