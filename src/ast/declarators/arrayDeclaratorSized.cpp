#include "arrayDeclaratorSized.hpp"
#include "utils.hpp"
#include "rvalue.hpp"

ArrayDeclaratorSized::ArrayDeclaratorSized(StatementPtr innerDeclarator, StatementPtr sizeSpecifier)
{
    branches.push_back(innerDeclarator);
    branches.push_back(sizeSpecifier);
}  

DeclaratorPtr ArrayDeclaratorSized::getChild() const{
    return Utils::tryCast<Declarator>(branches[0], "inner child of an array declarator must be a declarator");
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

void ArrayDeclaratorSized::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    RValuePtr rvalue = Utils::tryCast<RValue>(getSizeSpecifier(), "size specifer of an array must be an rvalue");
    if (!rvalue->isConstant()) { throw "size specifier of an array must be a constant"; }

    std::string arrayName = context.makeName(getIdentifierName());
    int arraySize = rvalue->evalConst();
    instrs.push_back(Instr("decl", arrayName, std::to_string(arraySize * 4)));
    instrs.push_back(Instr("loc", getIdentifierName(), arrayName));
}