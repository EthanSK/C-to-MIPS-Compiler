#ifndef directDeclarator_hpp
#define directDeclarator_hpp

#include "declarator.hpp"
#include "identifier.hpp"

class DirectDeclarator : public Declarator
{
public:
  DirectDeclarator(StatementPtr identifier);
  DirectDeclarator(std::string name) : DirectDeclarator(new Identifier(name)) { } 
  StatementPtr getIdentifier() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  void printC(std::ostream &os) const override;
  virtual std::string getIdentifierName() const override;
  virtual DeclTypeEnum declType() const override { return DeclTypeEnum::direct; }
};

#endif
