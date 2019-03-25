#ifndef identifier_hpp
#define identifier_hpp

#include "statement.hpp"
#include "lvalue.hpp"
#include "rvalue.hpp"

class Identifier;
typedef const Identifier* IdentifierPtr;

class Identifier : public Statement, public LValue, public RValue
{
public:
  Identifier(std::string name);
  std::string getName() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
  void generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const override;
  bool isConstant() const override;
  int evalConst() const override;

protected:
  void printC(std::ostream &os) const override;

private:
  std::string _name;
};

#endif