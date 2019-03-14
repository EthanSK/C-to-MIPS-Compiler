#include "binaryBitwiseAndAssignment.hpp"

void BinaryBitwiseAndAssignment::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " &= " << getRight() << ")";
}

void BinaryBitwiseAndAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " &= ";
	getRight()->generatePython(os, context, scopeDepth);
}