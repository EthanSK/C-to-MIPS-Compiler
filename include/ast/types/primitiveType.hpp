#ifndef primitiveType_hpp
#define primitiveType_hpp

#include "type.hpp"

class PrimitiveType : public Type //only terminal type
{ //wrapper class for the enum type
public:
  enum PrimitiveTypeEnum 
  {
    _void,
    _int,
    _float,
    _double,
    _char,
    _signed,
    _unsigned,
    _long
    //these are all we need appaz
  };

public:
  PrimitiveType(PrimitiveTypeEnum type) : _type(type){};

protected:
  PrimitiveTypeEnum _type;
  std::string primitiveTypeToString() const;
  virtual void printC(std::ostream &os) const override;
};

#endif