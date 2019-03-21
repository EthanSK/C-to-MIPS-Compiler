#include "binaryBitwiseAnd.hpp"
#include <sstream>

void BinaryBitwiseAnd::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " & ";
	os << getRight();
	os << ")";
}

void BinaryBitwiseAnd::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " & ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryBitwiseAnd::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("and_l");
	std::string rightReg = context.makeName("and_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("and", destReg, leftReg, rightReg));
}