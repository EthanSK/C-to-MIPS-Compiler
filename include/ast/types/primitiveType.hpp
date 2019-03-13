#ifndef primitiveType_hpp
#define primitiveType_hpp

#include "statement.hpp"

class PrimitiveType : public Statement
{ //wrapper class for the enum type
protected:
  enum class PrimitiveTypeEnum //enum class not enum so we guarantee strongly typed
  {
    _void,
    _int,
    _float,
    _double,
    _char,
    _unsigned
    //these are all we need appaz
  };
  std::string primitiveTypeToString();
  virtual void printC(std::ostream &os) const override;
};

#endif