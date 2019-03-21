#include "binaryLessThan.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryLessThan::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " < ";
	os << getRight();
	os << ")";
}

void BinaryLessThan::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " < ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryLessThan::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("lt_l");
	std::string rightReg = context.makeName("lt_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("lt", destReg, leftReg, rightReg));
}