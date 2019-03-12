#include "variableDeclarationList.hpp"

std::vector<StatementPtr> VariableDeclarationList::getVariables() const {
    return branches;
} 

