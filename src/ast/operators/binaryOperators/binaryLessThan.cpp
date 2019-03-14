#include "binaryLessThan.hpp"

void BinaryLessThan::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " < " << getRight() << ")";
}

void BinaryLessThan::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " < ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}