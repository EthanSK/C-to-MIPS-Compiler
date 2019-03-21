#include "binaryDivideAssignment.hpp"
#include <sstream>

void BinaryDivideAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " /= ";
	os << getRight();
}

void BinaryDivideAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " //= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryDivideAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftVar = getLeft()->toString(); //div.eq_l
	std::string rightReg = context.makeName("div.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("div.eq", destReg, leftVar, rightReg));
}