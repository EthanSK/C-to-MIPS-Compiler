#include "il2mips.hpp"

void IL2MIPS::retv(Instr instr, MIPSContext &context) 
{
    int stackSize = context.getAllocator().stackSize();
    context.addInstr(Instr("mov", "$v0", instr.dest));
    context.addInstr(Instr("mov", "$fp", "0_fp"));
    if (stackSize > 0) { context.addInstr(Instr("addi", "$sp", "$sp", std::to_string(stackSize))); }
    context.addInstr(Instr("jr", "$ra"));
    context.addInstr(Instr("nop"));
}