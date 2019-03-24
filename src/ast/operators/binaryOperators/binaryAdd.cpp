#include "binaryAdd.hpp"
#include "lvalue.hpp"
#include "utils.hpp"
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

void BinaryAdd::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "add";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	context.compileInput(getLeft(), instrs, leftReg);
	context.compileInput(getRight(), instrs, rightReg);
	instrs.push_back(Instr(opcode, destReg, leftReg, rightReg));
}

int BinaryAdd::evalConst() const
{
	return getLeftR()->evalConst() + getRightR()->evalConst();
}