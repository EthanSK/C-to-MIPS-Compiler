#ifndef instrPrinter_hpp
#define instrPrinter_hpp

#include "instr.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class InstrPrinter
{
  public:
    static void printInstrs(std::ostream &os, std::vector<Instr> instrs);
    static void writeMIPStoFile(std::string filePath, std::vector<Instr> instrs);
};

#endif