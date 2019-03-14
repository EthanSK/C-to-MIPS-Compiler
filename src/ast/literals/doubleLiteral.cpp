#include "doubleLiteral.hpp"

DoubleLiteral::DoubleLiteral(double value)
{
	_value = value;
}


void DoubleLiteral::printC(std::ostream &os) const
{
	os << _value;
}

void DoubleLiteral::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << _value;
}