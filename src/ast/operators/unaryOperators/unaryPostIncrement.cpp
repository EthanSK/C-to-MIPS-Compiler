#include "unaryPostIncrement.hpp"
#include "utils.hpp"
#include "lvalue.hpp"

void UnaryPostIncrement::printC(std::ostream &os) const
{
	os << getOperand() << "++";
}

void UnaryPostIncrement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(Instr("mov", destReg, "$t0"));
	instrs.push_back(Instr("inc", "$t0"));
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "Illegal ++: " + toString() + ". LHS of an increment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, "$t0");
}

bool UnaryPostIncrement::isConstant() const { return false; }
int UnaryPostIncrement::evalConst() const { throw "cannot statically evaluate an increment"; }