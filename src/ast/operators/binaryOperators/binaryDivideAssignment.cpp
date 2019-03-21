#include "binaryDivideAssignment.hpp"

void BinaryDivideAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " /= ";
	os << getRight();
}

void BinaryDivideAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " //= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryDivideAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = "_divideAssignment_l";
	std::string rightReg = "_divideAssignment_r";
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("divideAssignment", destReg, leftReg, rightReg));
}