#include "il2mips.hpp"

void IL2MIPS::ret(MIPSContext &context) 
{
    int stackSize = context.getAllocator().stackSize();
    context.addInstr(Instr("move", "$fp", "0_fp"));
    context.addInstr(Instr("move", "$ra", "0_ra"));
    if (stackSize > 0) { context.addInstr(Instr("addi", "$sp", "$sp", std::to_string(stackSize), {"#pop"})); }
    context.addInstr(Instr("jr", "$ra"));
    context.addInstr(Instr("nop"));
}