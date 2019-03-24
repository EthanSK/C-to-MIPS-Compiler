#include "unaryBitwiseInvert.hpp"

void UnaryBitwiseInvert::printC(std::ostream &os) const
{
	os << "~(" << getOperand() << ")";
}

void UnaryBitwiseInvert::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "~(";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}

void UnaryBitwiseInvert::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("neg", destReg, "$t0"));
}

int UnaryBitwiseInvert::evalConst() const
{
	return ~getOperandR()->evalConst();
}