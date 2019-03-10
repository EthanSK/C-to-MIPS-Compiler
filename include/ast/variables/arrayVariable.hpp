#ifndef primitiveType_hpp
#define primitiveType_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variable.hpp"
#include "primitiveVariable.hpp"


class ArrayVariable : Variable //branch[0] contains the literal value if at all. 
{
  public:
    PrimitiveVariable type;
    int size;
  //  ArrayVariable(PrimitiveVariable::Type _type, int _size) : type(_type), size(_size) {};//must be init'ed with a type value or makes no sense
//  std::string typeToString() const; //converts the Type enum case to a string value that can be used in printC or elsewhere. not in the base Variable class because for eg the arrayvariable class that inherits from this can use primitivevar typeToString within printC as well, but makes no sense to use arrayvariable typetostring coz would be int [50] when we wanna print int a[50]

  protected: 
    void printC(std::ostream &os) const; 
};

#endif
