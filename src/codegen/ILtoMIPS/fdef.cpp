#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr::makeLabel(instr.dest + "()"));
    context.pushFrame();
    context.addInstr(Instr("mov", "0_fp", "$fp"));
    context.addInstr(Instr("mov", "0_ra", "$ra"));
}