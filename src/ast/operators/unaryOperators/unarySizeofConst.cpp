#include "unarySizeofConst.hpp"
#include <string>
#include "type.hpp"

void UnarySizeofConst::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    int size = reinterpret_cast<TypePtr>(getOperand())->getTypeSize();
    instrs.push_back(ILinstr("movi", destReg, std::to_string(size)));
}