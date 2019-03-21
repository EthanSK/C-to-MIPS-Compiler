#include "binaryLogicalOr.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryLogicalOr::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " || ";
	os << getRight();
	os << ")";
}

void BinaryLogicalOr::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " or ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryLogicalOr::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("orl_l");
	std::string rightReg = context.makeName("orl_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("orl", destReg, leftReg, rightReg));
}