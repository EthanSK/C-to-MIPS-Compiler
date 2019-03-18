#ifndef typeQualifier_hpp
#define typeQualifier_hpp

#include "statement.hpp"

class TypeQualifier : public Statement
{
public:
  enum TypeQualifierEnum 
  {
    _const,
    _volatile
  };

public:
  TypeQualifier(TypeQualifierEnum type) : _type(type){};

protected:
  TypeQualifierEnum _type;
  std::string typeQualifierToString() const;
  virtual void printC(std::ostream &os) const override;
};

#endif