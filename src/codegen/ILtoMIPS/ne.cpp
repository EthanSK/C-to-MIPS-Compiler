#include "il2mips.hpp"

void IL2MIPS::ne(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("xor", instr.dest, instr.input1, instr.input2));
}