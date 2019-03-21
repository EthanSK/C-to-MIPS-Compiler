#include "binaryIsNotEqualTo.hpp"

void BinaryIsNotEqualTo::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " != ";
	os << getRight();
	os << ")";
}

void BinaryIsNotEqualTo::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " != ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryIsNotEqualTo::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("ne_l");
	std::string rightReg = context.makeName("ne_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("ne", destReg, leftReg, rightReg));
}