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
	//ASSIGNMENT VERSION
	std::string leftReg = context.makeName("div.eq_l");
	std::string rightReg = context.makeName("div.eq_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("div.eq", destReg, leftReg, rightReg));
}