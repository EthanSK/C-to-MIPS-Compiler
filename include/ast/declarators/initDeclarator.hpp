#ifndef initDeclarator_hpp
#define initDeclarator_hpp

#include "declarator.hpp"

class InitDeclarator : public Declarator
{
public:
    InitDeclarator(StatementPtr declarator, StatementPtr initializer);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    DeclaratorPtr getDeclarator() const;
    StatementPtr getInitializer() const;
  
protected:
    virtual void printC(std::ostream &os) const override;
    virtual std::string getIdentifierName() const override;
    virtual DeclTypeEnum declType() const override { return DeclTypeEnum::init; }
};

#endif
