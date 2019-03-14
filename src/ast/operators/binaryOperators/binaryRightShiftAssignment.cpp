#include "binaryRightShiftAssignment.hpp"

void BinaryRightShiftAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " >>= " << getRight() << ")";
}

void BinaryRightShiftAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " >>= ";
	getRight()->generatePython(os, context, scopeDepth);
}