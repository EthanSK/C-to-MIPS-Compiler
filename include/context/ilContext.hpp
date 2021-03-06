#ifndef ilContext_hpp
#define ilContext_hpp

#include "context.hpp"
#include "instr.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>

class Statement;
typedef const Statement *StatementPtr;

class ILContext : public Context
{
public:
  std::string makeName(std::string name);
  std::string makeLabelName(std::string name);
  void compileInput(StatementPtr input, std::vector<Instr> &instrs, std::string destReg);

    void registerFuncSymbol(std::string symbolName);
    bool isFuncSymbolDefined(std::string symbolName) const;

    void pushLoopLabels(std::string startLabel, std::string endLabel); 
    void popLoopLabels();                                              //pops last element
    std::tuple<std::string, std::string> getLastLoopLabel();

  private:
    std::set<std::string> _funcSymbols;
    std::unordered_map<std::string, int> _registeredNames;
    std::vector<std::tuple<std::string, std::string>> _loopLabelStack; //to keep track of labels for break and continue for eg. - tuple.0 is loop start label and tuple.1 is loop end label
};

#endif