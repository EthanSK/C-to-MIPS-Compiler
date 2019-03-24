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
    else if (instr.opcode == "add") { IL2MIPS::add(instr, context); }
    else if (instr.opcode == "addi") { IL2MIPS::addi(instr, context); }
    else if (instr.opcode == "sub") { IL2MIPS::sub(instr, context); }
    else if (instr.opcode == "subi") { IL2MIPS::subi(instr, context); }
    else if (instr.opcode == "mul") { IL2MIPS::mul(instr, context); }
    else if (instr.opcode == "div") { IL2MIPS::mul(instr, context); }
    else if (instr.opcode == "mod") { IL2MIPS::mod(instr, context); }
    else if (instr.opcode == "lt") { IL2MIPS::lt(instr, context); }
    else if (instr.opcode == "lte") { IL2MIPS::lte(instr, context); }
    else if (instr.opcode == "gt") { IL2MIPS::gt(instr, context); }
    else if (instr.opcode == "gte") { IL2MIPS::gte(instr, context); }
    else if (instr.opcode == "b") { IL2MIPS::b(instr, context); }
    else if (instr.opcode == "bez") { IL2MIPS::bez(instr, context); }
    else if (instr.opcode == "bnez") { IL2MIPS::bnez(instr, context); }
    else if (instr.opcode == "xor") { IL2MIPS::xorM(instr, context); }
    else if (instr.opcode == "nop") { context.addInstr(instr); }
    else if (instr.opcode == "") { context.addInstr(instr); } //for labels without opcode 
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}