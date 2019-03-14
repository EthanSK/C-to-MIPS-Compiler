#include "binaryModuloAssignment.hpp"

void BinaryModuloAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " %= " << getRight() << ")";
}

void BinaryModuloAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " %= ";
	getRight()->generatePython(os, context, scopeDepth);
}