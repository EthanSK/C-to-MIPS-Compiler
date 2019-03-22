#include "unarySizeofConst.hpp"
#include <string>
#include "type.hpp"
#include "utils.hpp"

void UnarySizeofConst::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    int size = Utils::tryCast<Type>(getOperand(), "operand of const sizeof operator must be a type")->getTypeSize();
    instrs.push_back(Instr("li", destReg, std::to_string(size)));
}