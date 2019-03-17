#include "unaryAdd.hpp"

void UnaryAdd::printC(std::ostream &os) const
{
	os << "+(" << getOperand() << ")";
}

void UnaryAdd::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "+(";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}