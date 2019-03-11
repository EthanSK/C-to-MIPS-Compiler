#include "stringLiteral.hpp"

std::string StringLiteral::getValue() const
{
	return value;
}

void StringLiteral::printC(std::ostream &os) const
{
	os << "\"" << value << "\"";
}