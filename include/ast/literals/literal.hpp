#ifndef literal_hpp
#define literal_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "rvalue.hpp"

class Literal : public Statement, public RValue //Literal is an interface for all the literal types
{
public:
    virtual bool isConstant() const override { return true; }

protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
