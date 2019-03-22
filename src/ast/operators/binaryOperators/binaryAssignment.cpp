#include "binaryAssignment.hpp"
#include "lvalue.hpp"
#include "utils.hpp"
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

void BinaryAssignment::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "mov";
	std::string rightReg = context.makeName(opcode + "_r");
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(Instr("mov", destReg, rightReg));
	LValuePtr lvalue = Utils::tryCast<LValue>(getLeft(), "Illegal " + opcode + ": " + toString() + ". LHS of an assignment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, rightReg);
}