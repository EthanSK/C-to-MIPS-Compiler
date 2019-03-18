#ifndef ternaryOperator_hpp
#define ternaryOperator_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class TernaryOperator : public Statement
{
  public:
    TernaryOperator(StatementPtr condition, StatementPtr trueSelect, StatementPtr falseSelect);

  protected:
    StatementPtr getCondition() const;
    StatementPtr getTrueSelect() const;
    StatementPtr getFalseSelect() const;

    void printC(std::ostream &os) const; //prints c90 code so we can compare against input code //called in << overload
};

#endif
