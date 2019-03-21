#include "binaryIsEqualTo.hpp"
#include <sstream>

void BinaryIsEqualTo::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " == ";
	os << getRight();
	os << ")";
}

void BinaryIsEqualTo::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " == ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryIsEqualTo::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("eq_l");
	std::string rightReg = context.makeName("eq_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("eq", destReg, leftReg, rightReg));
}