#ifndef charLiteral_hpp
#define charLiteral_hpp

#include <iostream>
#include "literal.hpp"

class CharLiteral : Literal
{
  public:
    int value; // I don't think char can take multiple letters? IDK but clang uses an int to store the char literal value and then casts it implicitly
    void printC(std::ostream &os) const override;
};

#endif