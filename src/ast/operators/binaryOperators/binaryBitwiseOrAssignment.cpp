#include "binaryBitwiseOrAssignment.hpp"
#include <sstream>

void BinaryBitwiseOrAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " |= ";
	os << getRight();
}

void BinaryBitwiseOrAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " |= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryBitwiseOrAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftVar = getLeft()->toString(); //or.eq_l
	std::string rightReg = context.makeName("or.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("or.eq", destReg, leftVar, rightReg));
}