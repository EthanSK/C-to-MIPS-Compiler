#include "binaryLogicalOr.hpp"

void BinaryLogicalOr::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " || ";
	os << getRight();
	os << ")";
}

void BinaryLogicalOr::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " or ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}