#ifndef pointerDeclarator_hpp
#define pointerDeclarator_hpp

#include "declarator.hpp"

class PointerDeclarator : public Declarator
{
  public:
    PointerDeclarator(StatementPtr innerDeclarator);
    std::string getIdentifierName() const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

  protected:
    virtual DeclTypeEnum declType() const override { return DeclTypeEnum::pointer; }
    DeclaratorPtr getChild() const;
    void printC(std::ostream &os) const override;
};

#endif