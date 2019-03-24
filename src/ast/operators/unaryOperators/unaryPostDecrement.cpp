#include "unaryPostDecrement.hpp"
#include "utils.hpp"
#include "lvalue.hpp"

void UnaryPostDecrement::printC(std::ostream &os) const
{
	os << getOperand() << "--";
}

void UnaryPostDecrement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("mov", destReg, "$t0"));
	instrs.push_back(Instr("dec", "$t0"));
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "Illegal ++: " + toString() + ". LHS of an increment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, "$t0");
}

bool UnaryPostDecrement::isConstant() const { return false; }
int UnaryPostDecrement::evalConst() const { throw "cannot statically evaluate a decrement"; }