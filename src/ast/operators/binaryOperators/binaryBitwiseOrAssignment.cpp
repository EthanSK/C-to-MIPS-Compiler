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
	std::string leftReg = "_bitwiseOrAssignment_l";
	std::string rightReg = "_bitwiseOrAssignment_r";
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("bitwiseOrAssignment", destReg, leftReg, rightReg));
}