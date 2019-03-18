#ifndef pointerType_hpp
#define pointerType_hpp

#include "type.hpp"

class PointerType : public Type
{ 
  public:
    PointerType(StatementPtr child);
    TypePtr getChild() const;
  protected:
    void printC(std::ostream &os) const override;
};

#endif