#include "il2mips.hpp"

void IL2MIPS::retv(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    mipsInstrs.push_back(Instr("mov", "$v0", instr.dest));
    mipsInstrs.push_back(Instr("jr", "$ra"));
    mipsInstrs.push_back(Instr("nop"));
}