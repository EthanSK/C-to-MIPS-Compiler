#include "unaryAdd.hpp"

void UnaryAdd::printC(std::ostream &os) const
{
	os << "+(" << getOperand() << ")";
}

void UnaryAdd::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "+(";
	getOperand()->generatePython(os, context, scopeDepth);
	os << ")";
}

void UnaryAdd::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	getOperand()->generateIL(instrs, context, "doesnt_matter");
	//no need to add it to 0, makes no difference
}
