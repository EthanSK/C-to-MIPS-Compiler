#ifndef binaryOperator_hpp
#define binaryOperator_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "astStatement.hpp"


class BinaryOperator : Statement
{
    protected:
        StatementPtr getLeft() const;
        StatementPtr getRight() const;
};

#endif
