#ifndef arrayInitDeclarator_hpp
#define arrayInitDeclarator_hpp

#include "initDeclarator.hpp"

class ArrayInitDeclarator : public InitDeclarator
{
public:
    using InitDeclarator::InitDeclarator;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
};

#endif
