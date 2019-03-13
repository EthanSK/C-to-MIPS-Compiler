#ifndef charLiteral_hpp
#define charLiteral_hpp

#include <iostream>
#include "literal.hpp"

class CharLiteral : public Literal
{
  public:
    CharLiteral(int value);
    void printC(std::ostream &os) const override;

  private:
    int _value; // I don't think char can take multiple letters? IDK but clang uses an int to store the char literal value and then casts it implicitly
};

#endif