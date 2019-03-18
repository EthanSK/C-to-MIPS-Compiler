#ifndef arrayDeclarator_hpp
#define arrayDeclarator_hpp

#include "declarator.hpp"

class ArrayDeclarator : public Declarator
{
public:
    ArrayDeclarator(StatementPtr innerDeclarator);
    std::string getIdentifierName() const override;

protected:
    DeclaratorPtr getChild() const;
    void printC(std::ostream &os) const override;
};

#endif