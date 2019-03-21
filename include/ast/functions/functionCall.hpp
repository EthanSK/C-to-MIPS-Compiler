#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "statement.hpp"
#include "identifier.hpp"
#include "expressionList.hpp"

class FunctionCall : public Statement
{
public:
  FunctionCall(StatementPtr name, StatementPtr parameters);
  FunctionCall(std::string name, StatementPtr parameters) : FunctionCall(new Identifier(name), parameters) { }
  FunctionCall(StatementPtr name) : FunctionCall(name, new ExpressionList()) { }
  FunctionCall(std::string name) : FunctionCall(new Identifier(name)) { }
  
  StatementPtr getParameters() const;
  StatementPtr getName() const;

  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif