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

void UnaryMinus::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string innerReg = "temp_reg";
	getOperand()->generateIL(instrs, context, innerReg);
	ILinstr instr("sub", destReg, "0", innerReg); 
	instrs.push_back(instr);
	//-(5 + 2)
	//5 + 2 --> name  - inner
	//- <-- name   - outer
} 