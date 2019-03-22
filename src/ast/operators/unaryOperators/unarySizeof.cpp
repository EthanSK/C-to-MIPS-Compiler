#include "unarySizeof.hpp"

void UnarySizeof::printC(std::ostream &os) const
{
	os << "sizeof(" << getOperand() << ")";
}

void UnarySizeof::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    instrs.push_back(ILinstr("li", destReg, "4"));
}