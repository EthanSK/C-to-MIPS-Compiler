#include "unaryNot.hpp"

void UnaryNot::printC(std::ostream &os) const
{
	os << "!(" << getOperand() << ")";
}

void UnaryNot::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << " not (";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}

void UnaryNot::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(ILinstr("eq", destReg, "$0", "$t0"));
}