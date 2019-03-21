#include "binaryLeftShift.hpp"
#include "lvalue.hpp"
#include <sstream>

void BinaryLeftShift::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " << ";
	os << getRight();
	os << ")";
}

void BinaryLeftShift::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " << ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryLeftShift::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "lsl";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr(opcode, destReg, leftReg, rightReg));
}