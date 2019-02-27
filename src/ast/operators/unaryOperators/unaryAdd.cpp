#include "unaryAdd.hpp"

void UnaryAdd::printCode(std::ostream &os) const
{
	os << "+(" << getOperand() << ")";
}