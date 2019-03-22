#ifndef unarySizeof_hpp
#define unarySizeof_hpp

#include "unaryOperator.hpp"

class UnarySizeof : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 
