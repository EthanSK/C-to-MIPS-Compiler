#ifndef il2mips_hpp
#define il2mips_hpp

#include "instr.hpp"
#include "mipsContext.hpp"

class IL2MIPS //one IL may map to many MIPS
{
  public:
    static std::vector<Instr> convertToMIPS(std::vector<Instr> &instrs);

  private:
    static void convertInstr(Instr &instr, MIPSContext &context);

    static void li(Instr instr, MIPSContext &context);
    static void scu(Instr instr, MIPSContext &context);
    static void scd(Instr instr, MIPSContext &context);
    static void decl(Instr instr, MIPSContext &context);
    static void fdef(Instr instr, MIPSContext &context);
    static void fcall(Instr instr, MIPSContext &context);
    static void fend(Instr instr, MIPSContext &context);
    static void retv(Instr instr, MIPSContext &context);
    static void mov(Instr instr, MIPSContext &context);
    static void eq(Instr instr, MIPSContext &context);
    static void ne(Instr instr, MIPSContext &context);
    static void add(Instr instr, MIPSContext &context);
    static void addi(Instr instr, MIPSContext &context);
    static void sub(Instr instr, MIPSContext &context);
    static void subi(Instr instr, MIPSContext &context);
    static void mul(Instr instr, MIPSContext &context);
    static void div(Instr instr, MIPSContext &context);
    static void mod(Instr instr, MIPSContext &context);
    static void lt(Instr instr, MIPSContext &context);
    static void lte(Instr instr, MIPSContext &context);
    static void gt(Instr instr, MIPSContext &context);
    static void gte(Instr instr, MIPSContext &context);
    static void b(Instr instr, MIPSContext &context);
    static void bez(Instr instr, MIPSContext &context);
    static void bnez(Instr instr, MIPSContext &context);
    static void xorM(Instr instr, MIPSContext &context);
    static void andM(Instr instr, MIPSContext &context);
    static void andl(Instr instr, MIPSContext &context);
    static void orM(Instr instr, MIPSContext &context);
    static void orl(Instr instr, MIPSContext &context);
    static void lsl(Instr instr, MIPSContext &context);
    static void lsr(Instr instr, MIPSContext &context);
    static void neg(Instr instr, MIPSContext &context);
    static void inc(Instr instr, MIPSContext &context);
    static void dec(Instr instr, MIPSContext &context);
    static void init(Instr instr, MIPSContext &context);

    static void ret(MIPSContext &context);
};

#endif