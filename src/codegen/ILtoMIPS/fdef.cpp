#include "il2mips.hpp"

void IL2MIPS::fdef(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr::makeLabel(instr.dest + "()"));
    context.getAllocator().pushFrame();
}