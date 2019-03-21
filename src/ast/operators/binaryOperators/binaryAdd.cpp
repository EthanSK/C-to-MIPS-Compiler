#include "binaryAdd.hpp"
#include <sstream>

void BinaryAdd::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " + ";
	os << getRight();
	os << ")";
}

void BinaryAdd::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " + ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryAdd::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("add_l");
	std::string rightReg = context.makeName("add_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("add", destReg, leftReg, rightReg));
}