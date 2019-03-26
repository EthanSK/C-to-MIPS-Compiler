#include "unaryPostIncrement.hpp"
#include "utils.hpp"
#include "lvalue.hpp"

void UnaryPostIncrement::printC(std::ostream &os) const
{
	os << getOperand() << "++";
}

void UnaryPostIncrement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	std::string storageLabel = context.makeName("inc_t");
    getOperand()->generateIL(instrs, context, storageLabel);
	instrs.push_back(Instr("mov", destReg, storageLabel));
	instrs.push_back(Instr("inc", storageLabel));
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "Illegal ++: " + toString() + ". LHS of an increment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, storageLabel);
}

bool UnaryPostIncrement::isConstant() const { return false; }
int UnaryPostIncrement::evalConst() const { throw "cannot statically evaluate an increment"; }