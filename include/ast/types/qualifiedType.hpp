#ifndef qualifiedType_hpp
#define qualifiedType_hpp

#include "type.hpp"

class QualifiedType : public Type
{ 
  public:
    QualifiedType(StatementPtr child, StatementPtr qualifier);
    virtual int getTypeSize() const override;

  protected:
    TypePtr getChild() const;
    StatementPtr getQualifier() const;

    void printC(std::ostream &os) const override;
};

#endif