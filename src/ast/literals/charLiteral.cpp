#include "charLiteral.hpp"

int CharLiteral::getValue() const
{
	return value;
}
void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << value << "\'";
}