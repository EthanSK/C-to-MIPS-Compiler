#include "binaryRightShift.hpp"

void BinaryRightShift::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " >> ";
	os << getRight();
	os << ")";
}

void BinaryRightShift::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " >> ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryRightShift::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("lsr_l");
	std::string rightReg = context.makeName("lsr_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("lsr", destReg, leftReg, rightReg));
}