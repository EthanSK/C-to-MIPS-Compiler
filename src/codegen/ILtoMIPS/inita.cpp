#include "il2mips.hpp"

void IL2MIPS::inita(Instr instr, MIPSContext &context) 
{
    if (context.isGlobalScope())
    {
        for (size_t i = 0; i < instr.extraData.size(); ++i)
        {
            context.addRawInstr(Instr(".word", instr.extraData[i]));
        }
        context.addRawInstr(Instr(".align", "2"));
    }
    else
    {
        context.addInstr(Instr("move", "$t0", instr.dest));
        for (size_t i = 0; i < instr.extraData.size(); ++i)
        {
            context.addRawInstr(Instr("li", "$t1", instr.extraData[i]));
            context.addRawInstr(Instr("sw", "$t1", std::to_string(4 * i) + "($t0)"));
        }  
    }
}