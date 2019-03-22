#include "il2mips.hpp"

void IL2MIPS::decl(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    Allocation allocation(std::stoi(instr.input1), instr.dest);
    context.alloc(allocation, mipsInstrs);
}