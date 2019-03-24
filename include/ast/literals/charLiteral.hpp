#ifndef charLiteral_hpp
#define charLiteral_hpp

#include <iostream>
#include "literal.hpp"

class CharLiteral : public Literal
{
  public:
    CharLiteral(int value);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    virtual int evalConst() const override { return _value; }

  protected:
    void printC(std::ostream &os) const override;

  private:
    std::string getEscapedChar() const;
    int _value; // I don't think char can take multiple letters? IDK but clang uses an int to store the char literal value and then casts it implicitly
};

#endif