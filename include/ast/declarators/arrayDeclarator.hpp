#ifndef arrayDeclarator_hpp
#define arrayDeclarator_hpp

#include "declarator.hpp"

class ArrayDeclarator : public Declarator
{
  public:
    ArrayDeclarator(StatementPtr innerDeclarator);
    std::string getIdentifierName() const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

  protected:
    virtual DeclTypeEnum declType() const override { return DeclTypeEnum::array; }
    DeclaratorPtr getChild() const;
    void printC(std::ostream &os) const override;
};

#endif