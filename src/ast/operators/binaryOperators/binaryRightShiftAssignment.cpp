#include "binaryRightShiftAssignment.hpp"
#include <sstream>

void BinaryRightShiftAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " >>= ";
	os << getRight();
}

void BinaryRightShiftAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " >>= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryRightShiftAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftVar = getLeft()->toString(); //lsr.eq_l
	std::string rightReg = context.makeName("lsr.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("lsr.eq", destReg, leftVar, rightReg));
}