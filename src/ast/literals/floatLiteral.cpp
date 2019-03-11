#include "floatLiteral.hpp"

float FloatLiteral::getValue() const
{
	return value;
}

void FloatLiteral::printC(std::ostream &os) const
{
	os << value << "f";
}