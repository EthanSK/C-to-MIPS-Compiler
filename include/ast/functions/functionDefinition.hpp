#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "primitiveType.hpp"

class FunctionDefinition : public Statement //definition is NOT just declaration with scope blokc, the decl params can just be type without name unlike in definiton.
{
public:
  FunctionDefinition(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters, StatementPtr scopeBlock, bool _isPointer, bool _isExtern);
  StatementPtr getScopeBlock() const;
  StatementPtr getParameters() const;
  void printC(std::ostream &os) const override;

protected:
  std::string name;
  PrimitiveType primitiveType;

private:
  //function can't have array as return type
  bool isPointer;
  bool isExtern;
};

#endif