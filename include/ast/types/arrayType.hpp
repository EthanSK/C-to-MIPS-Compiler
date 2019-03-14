#ifndef arrayType_hpp
#define arrayType_hpp

#include "type.hpp"

class ArrayType : public Type
{ 

  public:
    ArrayType(StatementPtr child, int size);
    StatementPtr getChild() const;

  protected:
    int _size;
    void printC(std::ostream &os) const override;
};

#endif