#include "binaryBitwiseOr.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryBitwiseOr::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " | ";
	os << getRight();
	os << ")";
}

void BinaryBitwiseOr::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " | ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryBitwiseOr::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("or_l");
	std::string rightReg = context.makeName("or_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("or", destReg, leftReg, rightReg));
}