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

#endif 