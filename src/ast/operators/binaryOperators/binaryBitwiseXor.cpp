#include "binaryBitwiseXor.hpp"

void BinaryBitwiseXor::printC(std::ostream &os) const
{
	os << "(" << getLeft() << " ^ " << getRight() << ")";
}

void BinaryBitwiseXor::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " ^ ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}