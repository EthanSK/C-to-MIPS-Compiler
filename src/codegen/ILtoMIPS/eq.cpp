#include "il2mips.hpp"

void IL2MIPS::eq(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    mipsInstrs.push_back(Instr("xor", "$t0", instr.input1, instr.input2));
    mipsInstrs.push_back(Instr("sltiu", instr.dest, "$t0", "1"));
}