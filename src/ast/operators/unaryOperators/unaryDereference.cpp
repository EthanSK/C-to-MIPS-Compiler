#include "unaryDereference.hpp"

void UnaryDereference::printC(std::ostream &os) const
{
	os << "*(" << getOperand() << ")";
}

void UnaryDereference::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(ILinstr("load", destReg, "$t0", "$0"));
}