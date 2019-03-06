#include "statement.hpp"


std::ostream &operator<<(std::ostream &os, const Statement &statement)
{
     statement.printCode(os);
     return os;
}  

Statement::~Statement()
{
    for(size_t i = 0; i < branches.size(); i++)
    {
        delete branches[i];
    }
}