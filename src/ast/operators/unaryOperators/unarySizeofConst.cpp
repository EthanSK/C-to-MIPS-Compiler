#include "unarySizeofConst.hpp"
#include <string>
#include "type.hpp"
#include "utils.hpp"

void UnarySizeofConst::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    int size = evalConst();
    instrs.push_back(Instr("li", destReg, std::to_string(size)));
}

int UnarySizeofConst::evalConst() const
{
	return Utils::tryCast<Type>(getOperand(), "operand of const sizeof operator must be a type")->getTypeSize();
}

bool UnarySizeofConst::isConstant() const { return true; }