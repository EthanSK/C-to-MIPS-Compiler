#include "floatLiteral.hpp"

void FloatLiteral::printCode(std::ostream &os) const
{
	os << value << "f";
}