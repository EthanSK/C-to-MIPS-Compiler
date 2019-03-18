#include "arrayDeclaratorSized.hpp"

ArrayDeclaratorSized::ArrayDeclaratorSized(StatementPtr innerDeclarator, StatementPtr sizeSpecifier)
{
    branches.push_back(innerDeclarator);
    branches.push_back(sizeSpecifier);
}  

DeclaratorPtr ArrayDeclaratorSized::getChild() const{
    return reinterpret_cast<DeclaratorPtr>(branches[0]);
}

StatementPtr ArrayDeclaratorSized::getSizeSpecifier() const{
    return branches[1];
}

std::string ArrayDeclaratorSized::getIdentifierName() const{
    return getChild()->getIdentifierName();
}

void ArrayDeclaratorSized::printC(std::ostream &os) const
{
    os << getChild() << "[" << getSizeSpecifier() << "]";
} 