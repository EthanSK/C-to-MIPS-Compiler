#ifndef switchBlock_hpp
#define switchBlock_hpp

#include "scopeBlock.hpp"
#include "utils.hpp"
#include "switchCase.hpp"

class SwitchBlock : public ScopeBlock //needed to check if the branch it is about to genIL on is actually a case/default or just normal
{
  public:
    using ScopeBlock::ScopeBlock;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    using Statement::branches; //makes branches public (so we can use in switch)

    //uses same printC as scopeBlock
};

#endif
