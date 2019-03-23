#include "il2mips.hpp"

void IL2MIPS::ret(MIPSContext &context) 
{
    int stackSize = context.stackSize();
    context.addInstr(Instr("mov", "$fp", "0_fp"));
    context.addInstr(Instr("mov", "$ra", "0_ra"));
    if (stackSize > 0) { context.addInstr(Instr("addi", "$sp", "$sp", std::to_string(stackSize))); }
    context.addInstr(Instr("jr", "$ra"));
    context.addInstr(Instr("nop"));
}