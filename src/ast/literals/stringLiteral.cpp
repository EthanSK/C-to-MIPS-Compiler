#include "stringLiteral.hpp"

StringLiteral::StringLiteral(std::string value)
{
	_value = value;
}


void StringLiteral::printC(std::ostream &os) const
{
	os << "\"" << _value << "\"";
}

void StringLiteral::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "\"" << _value << "\"";
}