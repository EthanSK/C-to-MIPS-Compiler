#include "doubleLiteral.hpp"

double DoubleLiteral::getValue() const
{
	return value;
}

void DoubleLiteral::printC(std::ostream &os) const
{
	os << value;
}