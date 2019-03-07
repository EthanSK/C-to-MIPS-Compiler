#include "integerLiteral.hpp"

void IntegerLiteral::printCode(std::ostream &os) const
{
	os << value;
}