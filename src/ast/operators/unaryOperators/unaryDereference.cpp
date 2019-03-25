#include "unaryDereference.hpp"
#include "utils.hpp"

void UnaryDereference::printC(std::ostream &os) const
{
	os << "*(" << getOperand() << ")";
}

void UnaryDereference::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("load", destReg, "$t0", "0"));
}

void UnaryDereference::generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
	getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("store", inputReg, "$t0", "0"));
}

void UnaryDereference::generateLValueLocateIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "dereference must be used on an lvalue to be locatable");
	lvalue->generateLValueLocateIL(instrs, context, inputReg);
}

bool UnaryDereference::isConstant() const { return false; }
int UnaryDereference::evalConst() const { throw "cannot statically evaluate a dereference"; }