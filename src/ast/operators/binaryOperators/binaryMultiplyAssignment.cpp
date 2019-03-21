#include "binaryMultiplyAssignment.hpp"
#include <sstream>

void BinaryMultiplyAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " *= ";
	os << getRight();
}

void BinaryMultiplyAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " *= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryMultiplyAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftVar = getLeft()->toString(); //mul.eq_l
	std::string rightReg = context.makeName("mul.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("mul.eq", destReg, leftVar, rightReg));
}