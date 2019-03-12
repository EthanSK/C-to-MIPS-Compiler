#include "floatLiteral.hpp"

FloatLiteral::FloatLiteral(float _value)
{
	value = _value;
}

float FloatLiteral::getValue() const
{
	return value;
}

void FloatLiteral::printC(std::ostream &os) const
{
	os << value << "f";
}