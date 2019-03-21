#ifndef identifier_hpp
#define identifier_hpp

#include "statement.hpp"

class Identifier : public Statement
{
public:
  Identifier(std::string name);
  std::string getName() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  void printC(std::ostream &os) const override;

private:
  std::string _name;
};

#endif