#include "il2mips.hpp"

void IL2MIPS::convertToMIPS(std::vector<Instr> &instrs, std::vector<Instr> &mipsInstrs)
{
    MIPSContext context;
    convertToMIPS(instrs, context, mipsInstrs);
}

void IL2MIPS::convertToMIPS(std::vector<Instr> &instrs, MIPSContext &context, std::vector<Instr> &mipsInstrs)
{
    for (size_t i = 0; i < instrs.size(); i++)
    {
        convertInstr(instrs[i], context, mipsInstrs);
    }
}

void IL2MIPS::convertInstr(Instr &instr, MIPSContext &context, std::vector<Instr> &mipsInstrs)
{
    if (instr.opcode == "fdef") { IL2MIPS::fdef(instr, context, mipsInstrs); }
    else if (instr.opcode == "fend") { IL2MIPS::fend(instr, context, mipsInstrs); }
    else if (instr.opcode == "fcall") { IL2MIPS::fcall(instr, context, mipsInstrs); }
    else if (instr.opcode == "scu") { IL2MIPS::scu(instr, context, mipsInstrs); }
    else if (instr.opcode == "scd") { IL2MIPS::scd(instr, context, mipsInstrs); }
    else if (instr.opcode == "decl") { IL2MIPS::decl(instr, context, mipsInstrs); }
    else if (instr.opcode == "retv") { IL2MIPS::retv(instr, context, mipsInstrs); }
    else if (instr.opcode == "li") { IL2MIPS::li(instr, context, mipsInstrs); }
    else if (instr.opcode == "mov") { IL2MIPS::mov(instr, context, mipsInstrs); }
    else if (instr.opcode == "eq") { IL2MIPS::eq(instr, context, mipsInstrs); }
    else if (instr.opcode == "ne") { IL2MIPS::ne(instr, context, mipsInstrs); }
    else if (instr.opcode == "") { mipsInstrs.push_back(instr); } //for labels without opcode 
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}