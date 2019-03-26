#include "binaryLogicalOr.hpp"
#include "lvalue.hpp"
#include "utils.hpp"
#include <sstream>

void BinaryLogicalOr::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " || ";
	os << getRight();
	os << ")";
}

void BinaryLogicalOr::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " or ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryLogicalOr::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string opcode = "orl";
	std::string leftReg = context.makeName(opcode + "_l");
	std::string rightReg = context.makeName(opcode + "_r");
	std::string shortCircuit_lb = context.makeLabelName(opcode + "_sc");
	std::string end_lb = context.makeLabelName(opcode + "_end");

	context.compileInput(getLeft(), instrs, leftReg);
	instrs.push_back(Instr("bnez", shortCircuit_lb, leftReg));

	context.compileInput(getRight(), instrs, rightReg);
	instrs.push_back(Instr(opcode, destReg, leftReg, rightReg));
	instrs.push_back(Instr("b", end_lb));

	instrs.push_back(Instr::makeLabel(shortCircuit_lb));
	instrs.push_back(Instr("li", destReg, "1"));
	instrs.push_back(Instr::makeLabel(end_lb));
}

int BinaryLogicalOr::evalConst() const
{
	return getLeftR()->evalConst() || getRightR()->evalConst();
}