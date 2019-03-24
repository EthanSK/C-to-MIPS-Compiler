#include "unaryDereference.hpp"

void UnaryDereference::printC(std::ostream &os) const
{
	os << "*(" << getOperand() << ")";
}

void UnaryDereference::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("load", destReg, "$t0", "$0"));
}

bool UnaryDereference::isConstant() const { return false; }
int UnaryDereference::evalConst() const { throw "cannot statically evaluate a dereference"; }