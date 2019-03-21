#include "binaryRightShiftAssignment.hpp"
#include "lvalue.hpp"
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
	std::string leftReg = context.makeName("lsr.eq_l");
	std::string rightReg = context.makeName("lsr.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("lsr.eq", destReg, leftReg, rightReg));
	dynamic_cast<LValuePtr>(getLeft())->generateLValueStoreIL(instrs, context, leftReg);
}