#include "ternary.hpp"

TernaryOperator::TernaryOperator(StatementPtr condition, StatementPtr trueSelect, StatementPtr falseSelect)
{
        branches.push_back(condition);
        branches.push_back(trueSelect);
        branches.push_back(falseSelect);
} 

StatementPtr TernaryOperator::getCondition() const
{
        return branches[0];
}

StatementPtr TernaryOperator::getTrueSelect() const
{
        return branches[1];
}

StatementPtr TernaryOperator::getFalseSelect() const
{
        return branches[2];
}

void TernaryOperator::printC(std::ostream &os) const{
    os << "(" << getCondition() << ") ? " << getTrueSelect() << " : " << getFalseSelect();
}