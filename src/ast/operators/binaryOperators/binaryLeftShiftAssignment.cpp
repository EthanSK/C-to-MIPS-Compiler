#include "binaryLeftShiftAssignment.hpp"
#include <sstream>

void BinaryLeftShiftAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " <<= ";
	os << getRight();
}

void BinaryLeftShiftAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " <<= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryLeftShiftAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftVar = getLeft()->toString(); //lsl.eq_l
	std::string rightReg = context.makeName("lsl.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("lsl.eq", destReg, leftVar, rightReg));
}