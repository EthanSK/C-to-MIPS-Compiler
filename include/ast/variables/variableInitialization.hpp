#ifndef variableInitialization_hpp
#define variableInitialization_hpp

#include "statement.hpp"
#include "integerLiteral.hpp"

class VariableInitialization : public Statement
{
public:
  VariableInitialization(StatementPtr identifier, StatementPtr initializer);
  VariableInitialization(StatementPtr identifier) : VariableInitialization(identifier, new IntegerLiteral(0)) { }
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  StatementPtr getIdentifier() const;
  StatementPtr getInitializer() const;
  
protected:
  virtual void printC(std::ostream &os) const override;
};

#endif
