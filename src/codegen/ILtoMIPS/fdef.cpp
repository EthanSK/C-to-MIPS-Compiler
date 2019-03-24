#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    std::string funcSymbol = instr.dest;
    context.addRawInstr(Instr(".globl", funcSymbol));
    context.addRawInstr(Instr(".ent", funcSymbol));
    context.addRawInstr(Instr(".type", funcSymbol, "@function"));
    context.addInstr(Instr::makeLabel(funcSymbol));
    context.pushFrame();
    context.addInstr(Instr("move", "0_fp", "$fp"));
    context.addInstr(Instr("move", "0_ra", "$ra"));

    for (int i = 0; i < instr.extraData.size(); ++i)
    {
        if (i < 4)
        {
            context.addInstr(Instr("move", instr.extraData[i], "$a" + std::to_string(i)));
        }
    }
}