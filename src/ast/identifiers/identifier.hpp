#ifndef identifier_hpp
#define identifier_hpp

#include <iostream>
#include "stringLiteral.hpp"

class Identifier : public StringLiteral
{
  public:
    using StringLiteral::StringLiteral;

  protected:
    void printC(std::ostream &os) const override;
};

#endifo