#ifndef unarySizeofConst_hpp
#define unarySizeofConst_hpp

#include "unarySizeof.hpp"

class UnarySizeofConst : public UnarySizeof
{ 
    using UnarySizeof::UnarySizeof;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 