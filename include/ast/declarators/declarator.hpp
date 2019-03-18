#ifndef declarator_hpp
#define declarator_hpp

#include "statement.hpp"

class Declarator;
typedef const Declarator* DeclaratorPtr;

class Declarator : public Statement
{
public:
    virtual std::string getIdentifierName() const = 0;
};

#endif