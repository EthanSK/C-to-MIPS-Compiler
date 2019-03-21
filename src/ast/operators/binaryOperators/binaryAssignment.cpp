#include "binaryAssignment.hpp"
#include "lvalue.hpp"
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
	std::string opcode = "mov";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	std::string resultReg = context.makeName(opcode + "_res");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr(opcode, resultReg, leftReg, rightReg));
	instrs.push_back(ILinstr("mov", destReg, resultReg));
	dynamic_cast<LValuePtr>(getLeft())->generateLValueStoreIL(instrs, context, resultReg);
}