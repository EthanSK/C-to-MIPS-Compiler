#ifndef declarator_hpp
#define declarator_hpp

#include "statement.hpp"

class Declarator : public Statement
{
public:
    virtual std::string getIdentifierName() const = 0;
};

#endif