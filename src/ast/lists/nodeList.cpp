#include "nodeList.hpp"

NodeList::NodeList(std::vector<StatementPtr> nodes){
    branches = nodes; 
} 

std::vector<StatementPtr> NodeList::getNodes() const {
    return branches;
} 
