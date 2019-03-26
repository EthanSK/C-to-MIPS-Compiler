#include "unaryPostDecrement.hpp"
#include "utils.hpp"
#include "lvalue.hpp"

void UnaryPostDecrement::printC(std::ostream &os) const
{
	os << getOperand() << "--";
}

void UnaryPostDecrement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string storageLabel = context.makeName("dec_t");
    getOperand()->generateIL(instrs, context, storageLabel);
	instrs.push_back(Instr("mov", destReg, storageLabel));
	instrs.push_back(Instr("dec", storageLabel));
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "Illegal ++: " + toString() + ". LHS of an increment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, storageLabel);
}

bool UnaryPostDecrement::isConstant() const { return false; }
int UnaryPostDecrement::evalConst() const { throw "cannot statically evaluate a decrement"; }