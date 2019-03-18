#ifndef arrayDeclaratorSized_hpp
#define arrayDeclaratorSized_hpp

#include "declarator.hpp"

class ArrayDeclaratorSized : public Declarator
{
public:
    ArrayDeclaratorSized(StatementPtr innerDeclarator, StatementPtr sizeSpecifier);
    std::string getIdentifierName() const override;

protected:
    DeclaratorPtr getChild() const;
    StatementPtr getSizeSpecifier() const;
    void printC(std::ostream &os) const override;
};

#endif