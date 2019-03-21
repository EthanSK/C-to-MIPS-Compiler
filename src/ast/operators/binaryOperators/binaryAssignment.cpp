#include "binaryAssignment.hpp"
#include <sstream>

void BinaryAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " = ";
	os << getRight();
}

void BinaryAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " = ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftVar = getLeft()->toString(); //mov.eq_l
	std::string rightReg = context.makeName("mov.eq_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("mov.eq", destReg, leftVar, rightReg));
}