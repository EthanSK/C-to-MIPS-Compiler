#include "doubleLiteral.hpp"

DoubleLiteral::DoubleLiteral(double value)
{
	_value = value;
}


void DoubleLiteral::printC(std::ostream &os) const
{
	os << _value;
}