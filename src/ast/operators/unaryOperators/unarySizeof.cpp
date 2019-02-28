#include "unarySizeof.hpp"

void UnarySizeof::printCode(std::ostream &os) const
{
	os << "sizeof(" << getOperand() << ")";
}