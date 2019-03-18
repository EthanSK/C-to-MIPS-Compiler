#ifndef parserHelpers_hpp
#define parserHelpers_hpp

#include "statement.hpp"
#include <vector>

typedef std::vector<StatementPtr> StatementList;
typedef StatementList* StatementListPtr;

inline StatementListPtr initExprList(StatementPtr expr)
{
    StatementListPtr exprList = new StatementList();
    exprList->push_back(expr);

    return exprList;
}

inline StatementListPtr concatExprList(StatementListPtr exprList, StatementPtr expr)
{
    exprList->push_back(expr);
    return exprList;
}

class TestNode : public Statement
{

  public:
    std::string _id;
     TestNode(std::string id) : _id(id){
        std::cout << "Test node spawed: " << _id << std::endl;
    };


    void printC(std::ostream &os) const
    {
        os << "Test node printC: " <<  _id << std::endl;
    }
};

#endif