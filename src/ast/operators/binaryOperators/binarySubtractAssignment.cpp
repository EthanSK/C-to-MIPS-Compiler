#include "binarySubtractAssignment.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinarySubtractAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " -= ";
	os << getRight();
}

void BinarySubtractAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " -= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinarySubtractAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("sub.eq_l");
	std::string rightReg = context.makeName("sub.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("sub.eq", destReg, leftReg, rightReg));
	dynamic_cast<LValuePtr>(getLeft())->generateLValueStoreIL(instrs, context, leftReg);
}