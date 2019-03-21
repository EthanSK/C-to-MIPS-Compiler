#include "binaryGreaterThan.hpp"
#include <sstream>

void BinaryGreaterThan::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " > ";
	os << getRight();
	os << ")";
}

void BinaryGreaterThan::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " > ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryGreaterThan::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("gt_l");
	std::string rightReg = context.makeName("gt_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("gt", destReg, leftReg, rightReg));
}