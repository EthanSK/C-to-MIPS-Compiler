#include "floatLiteral.hpp"

void FloatLiteral::printC(std::ostream &os) const
{
	os << value << "f";
}