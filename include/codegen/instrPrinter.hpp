#ifndef instrPrinter_hpp
#define instrPrinter_hpp

#include "instr.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class InstrPrinter
{
  public:
    static void prettyPrintInstrs(std::ostream &os, std::vector<Instr> instrs);
    static void generateInstrs(std::ostream &os, std::vector<Instr> instrs); //normal print not pretty
    static void writeMIPStoFile(std::string filePath, std::vector<Instr> instrs);

  private:
    static std::string addCommaIfNeeded(std::string &str);
    
};

#endif