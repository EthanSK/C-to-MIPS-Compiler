#ifndef declaration_hpp
#define declaration_hpp

#include "statement.hpp"

class Declaration;
typedef const Declaration* DeclarationPtr;

class Declaration : public Statement
{

};

#endif