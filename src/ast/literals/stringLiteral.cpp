#include "stringLiteral.hpp"

StringLiteral::StringLiteral(std::string value)
{
	value = value;
}

std::string StringLiteral::getValue() const
{
	return value;
}

void StringLiteral::printC(std::ostream &os) const
{
	os << "\"" << value << "\"";
}