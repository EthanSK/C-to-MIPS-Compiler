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
	std::string innerLeftReg = "temp_reg_left";
	std::string innerRightReg = "temp_reg_right";
	getLeft()->generateIL(instrs, context, innerLeftReg);
	getRight()->generateIL(instrs, context, innerRightReg);
	instrs.push_back(ILinstr("bitwiseAndAssignment", destReg, innerLeftReg, innerRightReg));
}