#include "stringLiteral.hpp"

StringLiteral::StringLiteral(std::string value)
{
	_value = value;
}


void StringLiteral::printC(std::ostream &os) const
{
	os << "\"" << _value << "\"";
}