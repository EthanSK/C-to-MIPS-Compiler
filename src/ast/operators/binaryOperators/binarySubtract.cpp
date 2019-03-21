#include "binarySubtract.hpp"
#include <sstream>

void BinarySubtract::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " - ";
	os << getRight();
	os << ")";
}

void BinarySubtract::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " - ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinarySubtract::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("sub_l");
	std::string rightReg = context.makeName("sub_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("sub", destReg, leftReg, rightReg));
}