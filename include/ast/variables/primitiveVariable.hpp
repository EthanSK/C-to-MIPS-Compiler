#ifndef primitiveType_hpp
#define primitiveType_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variable.hpp"


class PrimitiveVariable : Variable //used to hold type information about a variable. other derived types consist of this eg array, pointer, struct etc
{
  public:
    enum Type
    {
        _int,
        _float,
        _double
    };
    
    Type type;
    PrimitiveVariable(Type _type) : type(_type) {};//must be init'ed with a type value or makes no sense
    std::string typeToString();

  protected: 
    void printC(std::ostream &os) const; 
};

#endif
