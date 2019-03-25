#ifndef arrayDeclaratorSized_hpp
#define arrayDeclaratorSized_hpp

#include "declarator.hpp"

class ArrayDeclaratorSized : public Declarator
{
  public:
    ArrayDeclaratorSized(StatementPtr innerDeclarator, StatementPtr sizeSpecifier);
    std::string getIdentifierName() const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

  protected:
    virtual DeclTypeEnum declType() const override { return DeclTypeEnum::array; }
    DeclaratorPtr getChild() const;
    StatementPtr getSizeSpecifier() const;
    void printC(std::ostream &os) const override;
};

#endif