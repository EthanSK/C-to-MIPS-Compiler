#include "il2mips.hpp"

void IL2MIPS::init(Instr instr, MIPSContext &context) 
{
    if (context.isGlobalScope())
    {
        context.removeGlobalInits(instr.dest);
        context.addRawInstr(Instr(".word", instr.input1));
        context.addRawInstr(Instr(".align", "2"));
    }
    else { context.addInstr(Instr("li", instr.dest, instr.input1), instr.label); }
}