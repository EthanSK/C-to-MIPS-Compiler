#ifndef switchCondition_hpp
#define switchCondition_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "rvalue.hpp"
#include "utils.hpp"

class SwitchCase;
typedef const SwitchCase *SwitchCasePtr;

class SwitchCase : public Statement
{
  public:
    SwitchCase(StatementPtr condition, StatementPtr scopeBlock);
    virtual void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    StatementPtr getCondition() const;  //the thing for the case that it needs to equal to
    StatementPtr getScopeBlock() const; //execution block

  protected:
    virtual void printC(std::ostream &os) const override;
};

#endif
