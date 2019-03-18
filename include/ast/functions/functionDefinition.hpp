#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "identifier.hpp"

class FunctionDefinition : public Statement //definition is NOT just declaration with scope blokc, the decl params can just be type without name unlike in definiton.
{
public:
  FunctionDefinition(StatementPtr type, StatementPtr name, StatementPtr parameters, StatementPtr scopeBlock);
  FunctionDefinition(StatementPtr type, std::string name, StatementPtr parameters, StatementPtr scopeBlock)
                    : FunctionDefinition(type, new Identifier(name), parameters, scopeBlock) { }

  StatementPtr getType() const;
  StatementPtr getName() const;
  StatementPtr getParameters() const;
  StatementPtr getScopeBlock() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif