#include "variableDeclarationList.hpp"

std::vector<StatementPtr> VariableDeclarationList::getVariableDeclarations() const {
    return branches;
} 

