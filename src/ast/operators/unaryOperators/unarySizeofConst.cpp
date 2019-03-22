#include "unarySizeofConst.hpp"
#include <string>
#include "type.hpp"

void UnarySizeofConst::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    int size = reinterpret_cast<TypePtr>(getOperand())->getTypeSize();
    instrs.push_back(Instr("movi", destReg, std::to_string(size)));
}