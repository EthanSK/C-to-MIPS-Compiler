#include "binaryModuloAssignment.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryModuloAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " %= ";
	os << getRight();
}

void BinaryModuloAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " %= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryModuloAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("mod.eq_l");
	std::string rightReg = context.makeName("mod.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("mod.eq", destReg, leftReg, rightReg));
	dynamic_cast<LValuePtr>(getLeft())->generateLValueStoreIL(instrs, context, leftReg);
}