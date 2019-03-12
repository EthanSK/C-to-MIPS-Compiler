#include "doubleLiteral.hpp"

DoubleLiteral::DoubleLiteral(double _value)
{
	value = _value;
}
double DoubleLiteral::getValue() const
{
	return value;
}

void DoubleLiteral::printC(std::ostream &os) const
{
	os << value;
}