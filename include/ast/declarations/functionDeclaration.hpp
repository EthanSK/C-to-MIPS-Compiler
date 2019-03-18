#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include "declaration.hpp"

class FunctionDeclaration : public Declaration
{
public:
  FunctionDeclaration(StatementPtr retType, StatementPtr decl);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  StatementPtr getRetType() const;
  StatementPtr getDecl() const;
  void printC(std::ostream &os) const override;
};

#endif