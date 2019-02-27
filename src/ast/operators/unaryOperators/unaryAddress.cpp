#include "unaryAddress.hpp"

void UnaryAddress::printCode(std::ostream &os) const
{
	os << "&(" << getOperand() << ")";
}