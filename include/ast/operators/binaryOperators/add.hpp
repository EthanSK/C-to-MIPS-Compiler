#ifndef add_hpp
#define add_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../binaryOperator.hpp"

class AddOperator : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
