#include "unaryBitwiseInvert.hpp"

void UnaryBitwiseInvert::printC(std::ostream &os) const
{
	os << "~(" << getOperand() << ")";
}

void UnaryBitwiseInvert::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "~(";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}