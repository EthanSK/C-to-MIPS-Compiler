#include "unarySizeof.hpp"

void UnarySizeof::printC(std::ostream &os) const
{
	os << "sizeof(" << getOperand() << ")";
}