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
	//ASSIGNMENT VERSION
	std::string leftReg = context.makeName("and.eq_l");
	std::string rightReg = context.makeName("and.eq_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("and.eq", destReg, leftReg, rightReg));
}