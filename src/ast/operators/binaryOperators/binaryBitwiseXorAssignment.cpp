#include "binaryBitwiseXorAssignment.hpp"

void BinaryBitwiseXorAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " ^= " << getRight() << ")";
}

void BinaryBitwiseXorAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " ^= ";
	getRight()->generatePython(os, context, scopeDepth);
}