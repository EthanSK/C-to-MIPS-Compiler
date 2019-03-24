#include "unarySizeof.hpp"

void UnarySizeof::printC(std::ostream &os) const
{
	os << "sizeof(" << getOperand() << ")";
}

void UnarySizeof::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    instrs.push_back(Instr("li", destReg, "4"));
}

bool UnarySizeof::isConstant() const { return false; }
int UnarySizeof::evalConst() const { throw "cannot statically evaluate a sizeof"; }