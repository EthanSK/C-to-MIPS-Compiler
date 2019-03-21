#include "binaryModulo.hpp"
#include <sstream>

void BinaryModulo::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " % ";
	os << getRight();
	os << ")";
}

void BinaryModulo::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " % ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryModulo::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string leftReg = context.makeName("mod_l");
	std::string rightReg = context.makeName("mod_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("mod", destReg, leftReg, rightReg));
}