#include "binaryAddAssignment.hpp"

void BinaryAddAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " += " << getRight() << ")";
}

void BinaryAddAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " += ";
	getRight()->generatePython(os, context, scopeDepth);
}