#include "binaryAddAssignment.hpp"

void BinaryAddAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " += ";
	os << getRight();
}

void BinaryAddAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " += ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryAddAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("addAssignment_l");
	std::string rightReg = context.makeName("addAssignment_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("addAssignment", destReg, leftReg, rightReg));
}