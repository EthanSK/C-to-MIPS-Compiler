#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    std::string funcSymbol = instr.dest;
    context.addRawInstr(Instr(".globl", funcSymbol));
    context.addInstr(Instr::makeLabel(funcSymbol));
    context.pushFrame();

    for (int i = 0; i < instr.extraData.size() / 2; ++i)
    {
        context.alloc(Allocation(std::stoi(instr.extraData[i * 2 + 1]), instr.extraData[i * 2]));
        if (i < 4)
        {
            context.addInstr(Instr("move", instr.extraData[i * 2], "$a" + std::to_string(i)));
        }
    }

    context.addInstr(Instr("move", "0_fp", "$fp"));
    context.addInstr(Instr("move", "0_ra", "$ra"));
}