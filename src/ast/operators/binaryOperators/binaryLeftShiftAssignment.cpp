#include "binaryLeftShiftAssignment.hpp"

void BinaryLeftShiftAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " <<= ";
	os << getRight();
}

void BinaryLeftShiftAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " <<= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryLeftShiftAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("leftShiftAssignment_l");
	std::string rightReg = context.makeName("leftShiftAssignment_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("leftShiftAssignment", destReg, leftReg, rightReg));
}