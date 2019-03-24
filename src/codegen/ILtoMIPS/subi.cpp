#include "il2mips.hpp"

void IL2MIPS::subi(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("addi", instr.dest, instr.input1, "-" + instr.input2), instr.label);
}