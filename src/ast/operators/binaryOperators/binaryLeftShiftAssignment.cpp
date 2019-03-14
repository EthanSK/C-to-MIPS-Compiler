#include "binaryLeftShiftAssignment.hpp"

void BinaryLeftShiftAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " <<= ";
	os << getRight();
}

void BinaryLeftShiftAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " <<= ";
	getRight()->generatePython(os, context, scopeDepth);
}