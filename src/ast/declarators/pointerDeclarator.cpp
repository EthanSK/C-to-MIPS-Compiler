#include "pointerDeclarator.hpp"
#include "utils.hpp"

PointerDeclarator::PointerDeclarator(StatementPtr innerDeclarator)
{
    branches.push_back(innerDeclarator);
}  

DeclaratorPtr PointerDeclarator::getChild() const{
    return Utils::tryCast<Declarator>(branches[0], "inner child of a pointer declarator must be a declarator");
}

std::string PointerDeclarator::getIdentifierName() const{
    return getChild()->getIdentifierName();
}

void PointerDeclarator::printC(std::ostream &os) const
{
    os << "*" << getChild();
} 

void PointerDeclarator::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getChild()->generateIL(instrs, context, destReg);
}
