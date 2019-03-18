#ifndef nodeList_hpp 
#define nodeList_hpp

#include "statement.hpp"

class NodeList;
typedef const NodeList* NodeListPtr;

class NodeList : public Statement
{
public:
    NodeList(std::vector<StatementPtr> nodes);
    NodeList() : NodeList(std::vector<StatementPtr>{}) { }
    std::vector<StatementPtr> getNodes() const;
};

#endif