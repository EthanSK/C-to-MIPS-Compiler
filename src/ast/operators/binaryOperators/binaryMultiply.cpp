#include "binaryMultiply.hpp"
#include "lvalue.hpp"
#include "utils.hpp"
#include <sstream>

void BinaryMultiply::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " * ";
	os << getRight();
	os << ")";
}

void BinaryMultiply::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " * ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryMultiply::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "mul";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	context.compileInput(getLeft(), instrs, leftReg);
	context.compileInput(getRight(), instrs, rightReg);
	instrs.push_back(Instr(opcode, destReg, leftReg, rightReg));
}

int BinaryMultiply::evalConst() const
{
	return getLeftR()->evalConst() * getRightR()->evalConst();
}