#include "unaryAdd.hpp"

void UnaryAdd::printCode(std::ostream &os) const override
{
	os << "+(" << getOperand() << ")";
}