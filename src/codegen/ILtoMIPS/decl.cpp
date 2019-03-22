#include "ILtoMIPS.hpp"

void ILtoMIPS::decl(ILinstr instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr) 
{
    Allocation alloc;
    alloc.name = instr.dest;
    alloc.size = std::stoi(instr.input1);
    
}