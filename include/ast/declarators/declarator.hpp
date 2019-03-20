#ifndef declarator_hpp
#define declarator_hpp

#include "statement.hpp"

class Declarator;
typedef const Declarator* DeclaratorPtr;

class Declarator : public Statement
{
public:
    enum class DeclTypeEnum
    {
        unknown = 0,
        direct = 1,
        func = 2,
        init = 3,
        param = 4,
        array = 5
    };

    virtual std::string getIdentifierName() const = 0;
    virtual DeclTypeEnum declType() const { return DeclTypeEnum::unknown; }
};

#endif