#ifndef storageClass_hpp
#define storageClass_hpp

#include "statement.hpp"

class StorageClass : public Statement
{
public:
  enum StorageClassSpecifierEnum 
  {
    _typedef,
    _extern,
    _static,
    _auto,
    _register
  };

public:
  StorageClass(StorageClassSpecifierEnum type) : _type(type){};

protected:
  StorageClassSpecifierEnum _type;
  std::string storageClassSpecifierToString() const;
  virtual void printC(std::ostream &os) const override;
};

#endif