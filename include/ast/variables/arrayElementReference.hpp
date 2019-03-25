#ifndef arrayElementReference_hpp
#define arrayElementReference_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "lvalue.hpp"
#include "rvalue.hpp"

class ArrayElementReference : public Statement, public RValue, public LValue
{
public:
    ArrayElementReference(StatementPtr arr, StatementPtr index);
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    void generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const override;
    void generateLValueLocateIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const override;
    bool isConstant() const override;
    int evalConst() const override;

protected:
  StatementPtr getArr() const;
  StatementPtr getIndex() const;
  void printC(std::ostream &os) const override;
};

#endif
