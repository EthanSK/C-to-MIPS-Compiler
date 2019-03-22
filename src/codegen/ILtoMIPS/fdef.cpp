#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr::makeLabel(instr.dest + "()"));
    context.getAllocator().pushFrame();
    context.alloc(Allocation(4, "0_fp"));
    context.addInstr(Instr("mov", "0_fp", "$fp"));
}