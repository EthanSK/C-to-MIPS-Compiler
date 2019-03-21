#include "binaryGreaterThanOrEqualTo.hpp"

void BinaryGreaterThanOrEqualTo::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " >= ";
	os << getRight();
	os << ")";
}

void BinaryGreaterThanOrEqualTo::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " >= ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryGreaterThanOrEqualTo::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("gte_l");
	std::string rightReg = context.makeName("gte_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("gte", destReg, leftReg, rightReg));
}