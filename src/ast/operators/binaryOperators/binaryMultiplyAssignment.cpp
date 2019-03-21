#include "binaryMultiplyAssignment.hpp"

void BinaryMultiplyAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " *= ";
	os << getRight();
}

void BinaryMultiplyAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " *= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryMultiplyAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = "_multiplyAssignment_l";
	std::string rightReg = "_multiplyAssignment_r";
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("multiplyAssignment", destReg, leftReg, rightReg));
}