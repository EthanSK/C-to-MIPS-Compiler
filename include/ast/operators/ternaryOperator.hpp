#ifndef ternaryOperator_hpp
#define ternaryOperator_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "rvalue.hpp"

class TernaryOperator : public Statement, public RValue
{
  public:
    TernaryOperator(StatementPtr condition, StatementPtr trueSelect, StatementPtr falseSelect);
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    bool isConstant() const override;
    int evalConst() const override;

  protected:
    StatementPtr getCondition() const;
    StatementPtr getTrueSelect() const;
    StatementPtr getFalseSelect() const;

    RValuePtr getConditionR() const;
    RValuePtr getTrueSelectR() const;
    RValuePtr getFalseSelectR() const;

    void printC(std::ostream &os) const override; //prints c90 code so we can compare against input code //called in << overload
};

#endif
