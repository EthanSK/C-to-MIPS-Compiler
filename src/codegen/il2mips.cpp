#include "il2mips.hpp"

std::vector<Instr> IL2MIPS::convertToMIPS(std::vector<Instr> &instrs)
{
    MIPSContext context;
    for (size_t i = 0; i < instrs.size(); i++)
    {
        convertInstr(instrs[i], context);
    }

    context.postProcessInstrs();
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
    else if (instr.opcode == "decla") { IL2MIPS::decla(instr, context); }
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
    else if (instr.opcode == "beq") { IL2MIPS::beq(instr, context); }
    else if (instr.opcode == "bez") { IL2MIPS::bez(instr, context); }
    else if (instr.opcode == "bne") { IL2MIPS::bne(instr, context); }
    else if (instr.opcode == "bnez") { IL2MIPS::bnez(instr, context); }
    else if (instr.opcode == "xor") { IL2MIPS::xorM(instr, context); }
    else if (instr.opcode == "and") { IL2MIPS::andM(instr, context); }
    else if (instr.opcode == "andl") { IL2MIPS::andl(instr, context); }
    else if (instr.opcode == "or") { IL2MIPS::orM(instr, context); }
    else if (instr.opcode == "orl") { IL2MIPS::orl(instr, context); }
    else if (instr.opcode == "lsl") { IL2MIPS::lsl(instr, context); }
    else if (instr.opcode == "lsr") { IL2MIPS::lsr(instr, context); }
    else if (instr.opcode == "neg") { IL2MIPS::neg(instr, context); }
    else if (instr.opcode == "inc") { IL2MIPS::inc(instr, context); }
    else if (instr.opcode == "dec") { IL2MIPS::dec(instr, context); }
    else if (instr.opcode == "init") { IL2MIPS::init(instr, context); }
    else if (instr.opcode == "loc") { IL2MIPS::loc(instr, context); }
    else if (instr.opcode == "load") { IL2MIPS::load(instr, context); }
    else if (instr.opcode == "store") { IL2MIPS::store(instr, context); }
    else if (instr.opcode == "pop") { IL2MIPS::pop(instr, context); }
    else if (instr.opcode == "nop") { context.addInstr(instr); }
    else if (instr.opcode == "") { context.addInstr(instr); } //for labels without opcode 
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}