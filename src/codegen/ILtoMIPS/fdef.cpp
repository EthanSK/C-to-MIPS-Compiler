#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr::makeLabel(instr.dest));
    context.pushFrame();
    context.addInstr(Instr("move", "0_fp", "$fp"));
    context.addInstr(Instr("move", "0_ra", "$ra"));
}