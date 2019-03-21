#include "binaryLogicalAnd.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryLogicalAnd::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " && ";
	os << getRight();
	os << ")";
}

void BinaryLogicalAnd::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " and ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryLogicalAnd::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("andl_l");
	std::string rightReg = context.makeName("andl_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("andl", destReg, leftReg, rightReg));
}