#include "il2mips.hpp"

void IL2MIPS::ne(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    mipsInstrs.push_back(Instr("xor", instr.dest, instr.input1, instr.input2));
}