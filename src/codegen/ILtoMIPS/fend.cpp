#include "il2mips.hpp"

void IL2MIPS::fend(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    mipsInstrs.push_back(Instr("jr", "$ra"));
    mipsInstrs.push_back(Instr("nop"));
}