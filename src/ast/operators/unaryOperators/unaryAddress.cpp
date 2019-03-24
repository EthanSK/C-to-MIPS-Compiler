#include "unaryAddress.hpp"

void UnaryAddress::printC(std::ostream &os) const
{
	os << "&(" << getOperand() << ")";
}

bool UnaryAddress::isConstant() const { return false; }
int UnaryAddress::evalConst() const { throw "cannot statically evaluate an address"; }