#include "binaryMultiply.hpp"
#include <sstream>

void BinaryMultiply::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " * ";
	os << getRight();
	os << ")";
}

void BinaryMultiply::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " * ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryMultiply::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("mul_l");
	std::string rightReg = context.makeName("mul_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("mul", destReg, leftReg, rightReg));
}