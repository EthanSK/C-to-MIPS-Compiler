#ifndef instrPrinter_hpp
#define instrPrinter_hpp

#include "instr.hpp"
#include <vector>
#include <iostream>

class InstrPrinter
{
public:
    static void printInstrs(std::ostream &os, std::vector<Instr> instrs);
};

#endif