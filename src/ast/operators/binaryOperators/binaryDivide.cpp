#include "binaryDivide.hpp"

void BinaryDivide::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " / ";
	os << getRight();
	os << ")";
}

void BinaryDivide::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " // ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryDivide::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("div_l");
	std::string rightReg = context.makeName("div_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("div", destReg, leftReg, rightReg));
}