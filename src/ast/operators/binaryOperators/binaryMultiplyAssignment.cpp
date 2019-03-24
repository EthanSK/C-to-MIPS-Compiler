#include "binaryMultiplyAssignment.hpp"
#include "lvalue.hpp"
#include "utils.hpp"
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

void BinaryMultiplyAssignment::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "mul";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	std::string resultReg = context.makeName(opcode + "_res");
	context.compileInput(getLeft(), instrs, leftReg);
	context.compileInput(getRight(), instrs, rightReg);
	instrs.push_back(Instr(opcode, resultReg, leftReg, rightReg));
	instrs.push_back(Instr("mov", destReg, resultReg));
	LValuePtr lvalue = Utils::tryCast<LValue>(getLeft(), "Illegal " + opcode + ": " + toString() + ". LHS of an assignment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, resultReg);
}