#ifndef ilContext_hpp
#define ilContext_hpp

#include "context.hpp"
#include "instr.hpp"
#include <string>
#include <vector>
#include <unordered_map>

class Statement;
typedef const Statement* StatementPtr;

class ILContext : public Context 
{
public:
    std::string makeName(std::string name);
    std::string makeLabelName(std::string name);
    void compileInput(StatementPtr input, std::vector<Instr> &instrs, std::string destReg);

private:
    std::unordered_map<std::string, int> _registeredNames;
    std::vector<std::string> _labelStack; //to keep track of labels for break and continue for eg
};

#endif