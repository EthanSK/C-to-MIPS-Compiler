#include "il2mips.hpp"

void IL2MIPS::mov(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    mipsInstrs.push_back(instr);
}