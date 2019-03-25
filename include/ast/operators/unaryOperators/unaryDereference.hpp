#ifndef unaryDereference_hpp
#define unaryDereference_hpp

#include "unaryOperator.hpp"
#include "lvalue.hpp"

class UnaryDereference : public UnaryOperator, public LValue
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    void generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const override;
    void generateLValueLocateIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const override;

    int evalConst() const override;
    bool isConstant() const override;
}; 
     
#endif 
