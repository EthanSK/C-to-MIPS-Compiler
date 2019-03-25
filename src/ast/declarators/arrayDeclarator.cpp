#include "arrayDeclarator.hpp"
#include "utils.hpp"

ArrayDeclarator::ArrayDeclarator(StatementPtr innerDeclarator)
{
    branches.push_back(innerDeclarator);
}  

DeclaratorPtr ArrayDeclarator::getChild() const{
    return Utils::tryCast<Declarator>(branches[0], "inner child of an array declarator must be a declarator");
}

std::string ArrayDeclarator::getIdentifierName() const{
    return getChild()->getIdentifierName();
}

void ArrayDeclarator::printC(std::ostream &os) const
{
    os << getChild() << "[]";
} 

void ArrayDeclarator::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    
}
