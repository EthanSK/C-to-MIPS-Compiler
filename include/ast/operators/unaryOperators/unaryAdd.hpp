#ifndef unaryAdd_hpp
#define unaryAdd_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../unaryOperator.hpp"

class UnaryAdd : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
