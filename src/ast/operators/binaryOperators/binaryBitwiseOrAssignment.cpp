#include "binaryBitwiseOrAssignment.hpp"

void BinaryBitwiseOrAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " |= ";
	os << getRight();
}

void BinaryBitwiseOrAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " |= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryBitwiseOrAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	//ASSIGNMENT VERSION
	std::string leftReg = context.makeName("or.eq_l");
	std::string rightReg = context.makeName("or.eq_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("or.eq", destReg, leftReg, rightReg));
}