#include "arrayDeclarator.hpp"

ArrayDeclarator::ArrayDeclarator(StatementPtr innerDeclarator)
{
    branches.push_back(innerDeclarator);
}  

DeclaratorPtr ArrayDeclarator::getChild() const{
    return reinterpret_cast<DeclaratorPtr>(branches[0]);
}

std::string ArrayDeclarator::getIdentifierName() const{
    return getChild()->getIdentifierName();
}

void ArrayDeclarator::printC(std::ostream &os) const
{
    os << getChild() << "[]";
} 