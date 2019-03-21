#include "binaryModuloAssignment.hpp"
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
	std::string leftVar = getLeft()->toString(); //mod.eq_l
	std::string rightReg = context.makeName("mod.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("mod.eq", destReg, leftVar, rightReg));
}