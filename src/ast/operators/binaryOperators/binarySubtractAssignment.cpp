#include "binarySubtractAssignment.hpp"

void BinarySubtractAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " -= ";
	os << getRight();
}

void BinarySubtractAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " -= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinarySubtractAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("subtractAssignment_l");
	std::string rightReg = context.makeName("subtractAssignment_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("subtractAssignment", destReg, leftReg, rightReg));
}