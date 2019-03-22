#include "binaryIsNotEqualTo.hpp"
#include "lvalue.hpp"
#include "utils.hpp"
#include <sstream>

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

void BinaryIsNotEqualTo::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "ne";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(Instr(opcode, destReg, leftReg, rightReg));
}