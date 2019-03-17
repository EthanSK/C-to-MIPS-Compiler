#include "unaryMinus.hpp"

void UnaryMinus::printC(std::ostream &os) const
{
	os << "-(" << getOperand() << ")";
}

void UnaryMinus::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "-(";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}