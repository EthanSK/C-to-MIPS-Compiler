#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    std::string funcSymbol = instr.dest;
    context.addRawInstr(Instr(".globl", funcSymbol));
    context.addInstr(Instr::makeLabel(funcSymbol));
    context.pushFrame();
    context.addInstr(Instr("move", "0_fp", "$fp"));
    context.addInstr(Instr("move", "0_ra", "$ra"));

    for (int i = 0; i < instr.extraData.size() / 2; ++i)
    {
        if (i < 4)
        {
            context.alloc(Allocation(std::stoi(instr.extraData[i * 2 + 1]), instr.extraData[i * 2]));
            context.addInstr(Instr("move", instr.extraData[i * 2], "$a" + std::to_string(i)));
        }
    }
}