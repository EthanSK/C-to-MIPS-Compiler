#ifndef declarator_hpp
#define declarator_hpp

#include "statement.hpp"

class Declarator : public Statement
{
public:
    StatementPtr getIdentifier() const = 0;
};

#endif