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
	std::string innerName = "temp_name";
	getOperand()->generateIL(instrs, context, innerName);
	ILinstr instr;
	instr.opcode = "sub";
	instr.dest = destReg;
	instr.in1 = "0";
	instr.in2 = innerName;
	instrs.push_back(instr);
	//-(5 + 2)
	//5 + 2 --> name  - inner
	//- <-- name   - outer
} 