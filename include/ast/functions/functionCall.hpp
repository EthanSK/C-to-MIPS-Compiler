#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "statement.hpp"
#include "identifier.hpp"

class FunctionCall : public Statement
{
public:
  FunctionCall(StatementPtr name, StatementPtr parameters); //parameters here won't be declarations even tho they use the func decl list (coz i'm lazy)
  FunctionCall(std::string name, StatementPtr parameters) : FunctionCall(new Identifier(name), parameters) { }
  StatementPtr getParameters() const;
  StatementPtr getName() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif