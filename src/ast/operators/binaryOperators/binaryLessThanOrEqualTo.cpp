#include "binaryLessThanOrEqualTo.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryLessThanOrEqualTo::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " <= ";
	os << getRight();
	os << ")";
}

void BinaryLessThanOrEqualTo::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " <= ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryLessThanOrEqualTo::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("lte_l");
	std::string rightReg = context.makeName("lte_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("lte", destReg, leftReg, rightReg));
}