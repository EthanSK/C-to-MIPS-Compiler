#include "variableDeclarationList.hpp"

VariableDeclarationList::VariableDeclarationList(std::vector<StatementPtr> variableDeclarations){
    branches = variableDeclarations; 
} 

VariableDeclarationList::VariableDeclarationList() { }

std::vector<StatementPtr> VariableDeclarationList::getVariableDeclarations() const {
    return branches;
} 

