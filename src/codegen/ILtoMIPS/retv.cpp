#include "il2mips.hpp"

void IL2MIPS::retv(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    int stackSize = context.getAllocator().stackSize();
    mipsInstrs.push_back(Instr("mov", "$v0", instr.dest));
    if (stackSize > 0) { mipsInstrs.push_back(Instr("addi", "$sp", std::to_string(stackSize))); }
    mipsInstrs.push_back(Instr("jr", "$ra"));
    mipsInstrs.push_back(Instr("nop"));
}