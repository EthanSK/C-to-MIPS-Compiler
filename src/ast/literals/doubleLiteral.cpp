#include "doubleLiteral.hpp"

DoubleLiteral::DoubleLiteral(double value)
{
	value = value;
}
double DoubleLiteral::getValue() const
{
	return value;
}

void DoubleLiteral::printC(std::ostream &os) const
{
	os << value;
}