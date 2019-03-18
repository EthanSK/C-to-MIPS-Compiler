#include "variableInitializationList.hpp"

VariableInitializationList::VariableInitializationList(std::vector<StatementPtr> initializations){
    branches = initializations; 
} 

std::vector<StatementPtr> VariableInitializationList::getInitializations() const {
    return branches;
} 

