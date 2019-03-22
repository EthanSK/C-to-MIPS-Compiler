#include "unaryPreDecrement.hpp"
#include "utils.hpp"
#include "lvalue.hpp"

void UnaryPreDecrement::printC(std::ostream &os) const
{
	os << "--(" << getOperand() << ")";
}

void UnaryPreDecrement::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    getOperand()->generateIL(instrs, context, "$t0");
	instrs.push_back(ILinstr("dec", "$t0"));
	instrs.push_back(ILinstr("mov", destReg, "$t0"));
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "Illegal ++: " + toString() + ". LHS of an increment must be an lvalue");
	lvalue->generateLValueStoreIL(instrs, context, "$t0");
}