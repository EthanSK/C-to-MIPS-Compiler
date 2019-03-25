#include "il2mips.hpp"

void IL2MIPS::init(Instr instr, MIPSContext &context) 
{
    if (context.isGlobalScope())
    {
        context.addRawInstr(Instr("la", "$t0", instr.input2));
        context.addInstr(Instr("move", instr.input1, "$t0"));
    }
    else
    {
        
    }
}