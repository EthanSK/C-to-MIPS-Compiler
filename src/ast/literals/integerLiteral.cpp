#include "integerLiteral.hpp"

int IntegerLiteral::getValue() const
{
	return value;
}
void IntegerLiteral::printC(std::ostream &os) const
{
	os << value;
}