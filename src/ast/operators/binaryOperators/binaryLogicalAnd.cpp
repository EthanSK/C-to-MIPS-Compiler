#include "binaryLogicalAnd.hpp"

void BinaryLogicalAnd::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " && ";
	os << getRight();
	os << ")";
}

void BinaryLogicalAnd::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " and ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}