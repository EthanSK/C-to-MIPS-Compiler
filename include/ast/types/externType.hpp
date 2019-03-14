#ifndef externType_hpp
#define externType_hpp

#include "type.hpp"

class ExternType : public Type
{ 
  public:
    ExternType(StatementPtr child);
    StatementPtr getChild() const;

  protected:
    void printC(std::ostream &os) const override;
};

#endif