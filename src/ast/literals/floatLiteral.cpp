#include "floatLiteral.hpp"

FloatLiteral::FloatLiteral(float value)
{
	_value = value;
}


void FloatLiteral::printC(std::ostream &os) const
{
	os << _value << "f";
}

void FloatLiteral::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << _value;
}