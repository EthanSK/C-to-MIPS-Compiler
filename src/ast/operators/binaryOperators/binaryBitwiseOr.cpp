#include "binaryBitwiseOr.hpp"

void BinaryBitwiseOr::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " | " << getRight() << ")";
}

void BinaryBitwiseOr::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " | ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}