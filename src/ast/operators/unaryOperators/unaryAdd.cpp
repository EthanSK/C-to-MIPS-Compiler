#include "unaryAdd.hpp"

void UnaryAdd::printC(std::ostream &os) const
{
	os << "+(" << getOperand() << ")";
}