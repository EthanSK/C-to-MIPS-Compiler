#include "il2mips.hpp"

void IL2MIPS::decl(Instr instr, MIPSContext &context, std::vector<Instr> &Instr) 
{
    Allocation alloc;
    alloc.name = instr.dest;
    alloc.size = std::stoi(instr.input1);
    
}