#include "binaryAddAssignment.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryAddAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " += ";
	os << getRight();
}

void BinaryAddAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " += ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryAddAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("add.eq_l");
	std::string rightReg = context.makeName("add.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("add.eq", destReg, leftReg, rightReg));
	dynamic_cast<LValuePtr>(getLeft())->generateLValueStoreIL(instrs, context, leftReg);
}