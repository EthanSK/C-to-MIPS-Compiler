#include "il2mips.hpp"

std::vector<Instr> IL2MIPS::convertToMIPS(std::vector<Instr> &instrs)
{
    MIPSContext context;
    for (size_t i = 0; i < instrs.size(); i++)
    {
        convertInstr(instrs[i], context);
    }

    return context.dumpInstrs();
}

void IL2MIPS::convertInstr(Instr &instr, MIPSContext &context)
{
    if (instr.opcode == "fdef") { IL2MIPS::fdef(instr, context); }
    else if (instr.opcode == "fend") { IL2MIPS::fend(instr, context); }
    else if (instr.opcode == "fcall") { IL2MIPS::fcall(instr, context); }
    else if (instr.opcode == "scu") { IL2MIPS::scu(instr, context); }
    else if (instr.opcode == "scd") { IL2MIPS::scd(instr, context); }
    else if (instr.opcode == "decl") { IL2MIPS::decl(instr, context); }
    else if (instr.opcode == "retv") { IL2MIPS::retv(instr, context); }
    else if (instr.opcode == "li") { IL2MIPS::li(instr, context); }
    else if (instr.opcode == "mov") { IL2MIPS::mov(instr, context); }
    else if (instr.opcode == "eq") { IL2MIPS::eq(instr, context); }
    else if (instr.opcode == "ne") { IL2MIPS::ne(instr, context); }
    else if (instr.opcode == "") { context.addInstr(instr); } //for labels without opcode 
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}