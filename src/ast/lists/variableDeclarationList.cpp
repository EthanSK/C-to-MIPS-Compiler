#include "variableDeclarationList.hpp"

VariableDeclarationList::VariableDeclarationList(std::vector<StatementPtr> variableDeclarations){
    branches = variableDeclarations; 
} 
std::vector<StatementPtr> VariableDeclarationList::getVariableDeclarations() const {
    return branches;
} 

