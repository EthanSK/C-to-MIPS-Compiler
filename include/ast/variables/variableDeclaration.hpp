#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "primitiveType.hpp"

class VariableDeclaration : public Statement
{
public:
  VariableDeclaration(PrimitiveType _primitiveType, std::string _name, bool _isPointer, bool _isExtern) : name(_name), arraySize(0), primitiveType(_primitiveType), isPointer(_isPointer), isArray(false), isExtern(_isExtern){};

  VariableDeclaration(PrimitiveType _primitiveType, std::string _name, bool _isArray, bool _isExtern, int _arraySize) : name(_name), primitiveType(_primitiveType), arraySize(_arraySize), isPointer(false), isArray(_isArray), isExtern(_isExtern){}; //use this constructor for arrays

  VariableDeclaration(PrimitiveType _primitiveType, std::string _name) : name(_name), primitiveType(_primitiveType), arraySize(0), isPointer(false), isArray(false), isExtern(false){}; //easy init without extra info

  std::string primitiveTypeToString() const;

protected:
  std::string name;
  PrimitiveType primitiveType;
  int arraySize; //if type even is array

private: //decided its better to do it like this that have a class for each one that inherits, because there could be many more properties like isPointer isArray to add. also allows us to be consistent for functions8
         //the combinations of these three are too hard to keep track of, so its easier, while worse practice, to have them like this and rely on the guaranteed correct input.
  bool isPointer;
  bool isArray;
  bool isExtern;

  virtual void printC(std::ostream &os) const;
};

#endif
