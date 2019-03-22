#ifndef Declaration_hpp
#define Declaration_hpp

#include "statement.hpp"
#include "declaratorList.hpp"

class Declaration : public Statement
{
public:
    Declaration(StatementPtr type, DeclaratorListPtr declList);
    Declaration(StatementPtr type, std::vector<StatementPtr> initList) : Declaration(type, new DeclaratorList(initList)) { }
    Declaration(StatementPtr type, StatementPtr decl) : Declaration(type, std::vector<StatementPtr>{decl}) { }
    Declaration(StatementPtr type) : Declaration(type, std::vector<StatementPtr>{}) { }
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
  
protected:
    StatementPtr getType() const;
    DeclaratorListPtr getDeclList() const;

    virtual void printC(std::ostream &os) const override;
};

#endif