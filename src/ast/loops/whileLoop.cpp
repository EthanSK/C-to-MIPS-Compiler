#include "whileLoop.hpp"

WhileLoop::WhileLoop(StatementPtr condition, StatementPtr scopeBlock){
    branches.push_back(condition);
    branches.push_back(scopeBlock); 
}

StatementPtr WhileLoop::getCondition() const{
    return branches[0];
}
StatementPtr WhileLoop::getScopeBlock() const{
    return branches[1];
}

void WhileLoop::printC(std::ostream &os) const 
{
    os << "while (" << getCondition() << ")" << getScopeBlock(); 
}

