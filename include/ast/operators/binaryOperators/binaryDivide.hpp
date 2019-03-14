#ifndef binaryDivide_hpp
#define binaryDivide_hpp


#include <iostream>
#include "binaryOperator.hpp"
#include "context.hpp"

class BinaryDivide : public BinaryOperator
{ 
public:
    using BinaryOperator::BinaryOperator;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    void printC(std::ostream &os) const override;
}; 
     
#endif 