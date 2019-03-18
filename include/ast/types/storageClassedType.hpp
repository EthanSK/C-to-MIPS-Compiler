#ifndef storageClassedType_hpp
#define storageClassedType_hpp

#include "type.hpp"

class StorageClassedType : public Type
{ 
  public:
    StorageClassedType(StatementPtr child, StatementPtr storageClass);

  protected:
    TypePtr getChild() const;
    StatementPtr getStorageClass() const;

    void printC(std::ostream &os) const override;
};

#endif