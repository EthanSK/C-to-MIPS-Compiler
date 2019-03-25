#ifndef arrayElementReference_hpp
#define arrayElementReference_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ArrayElementReference : public Statement
{
public:
  ArrayElementReference(StatementPtr arr, StatementPtr index);
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  StatementPtr getArr() const;
  StatementPtr getIndex() const;
  void printC(std::ostream &os) const;
};

#endif
