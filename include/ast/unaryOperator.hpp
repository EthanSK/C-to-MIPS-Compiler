
#ifndef unaryOperator_hpp
#define unaryOperator_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "astStatement.hpp"


class UnaryOperator : Statement
{
    protected:
        StatementPtr getOperand() const;
};

#endif
