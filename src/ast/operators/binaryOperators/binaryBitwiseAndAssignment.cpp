#include "binaryBitwiseAndAssignment.hpp"

void BinaryBitwiseAndAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " &= ";
	os << getRight();
}

void BinaryBitwiseAndAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " &= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryBitwiseAndAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = "_bitwiseAndAssignment_l";
	std::string rightReg = "_bitwiseAndAssignment_r";
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("bitwiseAndAssignment", destReg, leftReg, rightReg));
}