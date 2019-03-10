#ifndef primitiveType_hpp
#define primitiveType_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variable.hpp"


class PrimitiveVariable : public Variable //branch[0] contains the literal value if at all. 
{
  public:
    enum class Type //enum class not enum so we guarantee strongly typed
    {
        _int,
        _float,
        _double
    };
    Type type;
    PrimitiveVariable(Type _type) : type(_type) {};//must be init'ed with a type value or makes no sense
    std::string typeToString() const; //converts the Type enum case to a string value that can be used in printC or elsewhere. not in the base Variable class because for eg the arrayvariable class that inherits from this can use primitivevar typeToString within printC as well, but makes no sense to use arrayvariable typetostring coz would be int [50] when we wanna print int a[50]

  protected: 
    void printC(std::ostream &os) const; 
};

#endif
