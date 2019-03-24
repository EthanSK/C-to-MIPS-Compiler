#include "unaryMinus.hpp"

void UnaryMinus::printC(std::ostream &os) const
{
	os << "-(" << getOperand() << ")";
}

void UnaryMinus::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "-(";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}

void UnaryMinus::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("subi", destReg, "$0", "$t0"));
} 

int UnaryMinus::evalConst() const
{
	return -getOperandR()->evalConst();
}