#include "binaryLessThan.hpp"

void BinaryLessThan::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " < ";
	os << getRight();
	os << ")";
}

void BinaryLessThan::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " < ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}